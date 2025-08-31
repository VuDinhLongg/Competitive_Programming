// BidenJR
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ed "\n"
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define BidenJr 0
int x_4axis[] = {-1, 0, 0, 1};
int y_4axis[] = {0, -1, 1, 0};
int x_8axis[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y_8axis[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int MOD = 1e9 + 7;

ll gcdll(ll a, ll b) {
    return b == 0 ? llabs(a) : gcdll(b, a % b);
}

vector<ll> solve(ll n) {
    vector<ll> res;
    if (n < 2) return res;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) res.push_back(n);
    return res;
}

vector<int> sieve(int n) {
    vector<char> check_nt(n + 1, true);
    vector<int> nt;
    if (n < 2) return nt;
    check_nt[0] = check_nt[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (check_nt[i]) {
            for (int j = i * i; j <= n; j += i) 
                check_nt[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
        if (check_nt[i]) 
            nt.push_back(i);
    return nt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<ll> tmp(n + 1);
    vector<ll> b(n + 1);
    for (int i = 0; i <= n; i++) cin >> tmp[i];
    for (int i = 0; i <= n; i++) b[i] = tmp[n - i];
    ll g = 0;
    for (int i = 0; i <= n; i++) g = gcdll(g, llabs(b[i]));

    set<ll> res;
    if (g > 1) {
        vector<ll> fac = solve(g);
        for (auto p : fac) 
            res.insert(p);
    }

    vector<int> nt = sieve(n);
    for (int p : nt) {
        if (res.count(p)) 
            continue;
        
        vector<int> rem(p, 0);
        for (int i = 0; i <= n; i++) {
            int r;
            if (i < p) r = i;
            else {
                int t = (i - 1) / (p - 1);
                r = i - t * (p - 1);
            }
            int add = (int) ((b[i] % p + p) % p);
            rem[r] += add;
            if (rem[r] >= p) rem[r] -= p;
        }

        bool check = true;
        for (int r = 0; r < p; r++) {
            if (rem[r] % p != 0) {
                check = false; 
                break; 
            }
        }
        if (check) res.insert(p);
    }

    for (auto p : res) cout << p << ed;
    return 0;
}

