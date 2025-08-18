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

ll f3(int n, int m) {
    int oo = m + 1;
    map<tuple<int, int, int>, ll> dp;
    dp[{oo, oo, oo}] = 1;
    for (int i = 0; i < n; i++) {
        map<tuple<int, int, int>, ll> tmp;
        for (auto& p : dp) {
            auto [a, b, c] = p.first;
            ll cnt = p.second;
            for (int x = 1; x <= m; x++) {
                tuple<int, int, int> next_st;
                if (x <= a) {
                    next_st = {x, b, c};
                } else if (x <= b) {
                    next_st = {a, x, c};
                } else if (x <= c) {
                    next_st = {a, b, x};
                } else {
                    continue;
                }
                tmp[next_st] = (tmp[next_st] + cnt) % MOD;
            }
        }
        dp = move(tmp);
    }
    ll ans = 0;
    for (auto& p : dp) {
        ans = (ans + p.second) % MOD;
    }
    return ans;
}

ll f2(int n, int m) {
    int oo = m + 1;
    map<tuple<int, int>, ll> dp;
    dp[{oo, oo}] = 1;
    for (int i = 0; i < n; i++) {
        map<tuple<int, int>, ll> tmp;
        for (auto& p : dp) {
            auto [a, b] = p.first;
            ll cnt = p.second;
            for (int x = 1; x <= m; x++) {
                tuple<int, int> next_st;
                if (x <= a) {
                    next_st = {x, b};
                } else if (x <= b) {
                    next_st = {a, x};
                } else {
                    continue;
                }
                tmp[next_st] = (tmp[next_st] + cnt) % MOD;
            }
        }
        dp = move(tmp);
    }
    ll ans = 0;
    for (auto& p : dp) {
        ans = (ans + p.second) % MOD;
    }
    return ans;
}

int main() {
  	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    ll ans = (f3(n, m) - f2(n, m) + MOD) % MOD;
    cout << ans;
	  return BidenJr;
}
