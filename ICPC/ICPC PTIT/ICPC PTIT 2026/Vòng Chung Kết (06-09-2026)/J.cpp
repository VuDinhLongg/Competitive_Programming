#include <bits/stdc++.h>
using namespace std;

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x),end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 500'007

vector<int> kmp(const string &var){
    int n = var.size();
    string s = "%" + var;
    vector<int> f(n + 5);
    for(int i = 2, j = 0; i <= n; ++i){
        while(j and s[i] != s[j + 1]) j = f[j];
        if(s[i] == s[j + 1]) f[i] = ++j;
    }
    return f;
}

const int mod = 998244853;

array<vector<int>, 2> fbase;
array<int, 2> base;

void prepare(int n){
    base[0] = 67; base[1] = 367;
    fo(i, 0, 1){
        fbase[i].assign(n + 5, 1);
        fo(j, 1, n) fbase[i][j] = fbase[i][j - 1] * base[i] % mod;
    }
}

struct Hash{
    array<vector<int>, 2> h;
    Hash(const string &str){
        int n = str.size();
        fo(i, 0, 1){
            h[i].assign(n + 5, 0);
            fo(j, 1, n) h[i][j] = (h[i][j - 1] * base[i] + str[j - 1]) % mod;
        }
    }
    pair<int, int> get(int l, int r){
        int x = (h[0][r] - h[0][l - 1] * fbase[0][r - l + 1] % mod + mod) % mod;
        int y = (h[1][r] - h[1][l - 1] * fbase[1][r - l + 1] % mod + mod) % mod;
        return {x, y};
    }
};

int n;
string s;

bool check(int len, Hash &h){
    vector<int> pos;
    fo(i, 1, n - len + 1) if(h.get(1, len) == h.get(i, i + len - 1)){
        pos.push_back(i);
    }
//    cout << len, el; for(int &i : pos) cout << i << ' '; el;
    fo(i, 1, len(pos) - 1){
        int x = pos[i - 1];
        int y = pos[i];
        if(x + len - 1 + 1 < y) return 0;
        if(x + len - 1 + 1 > y){
            int tmp = x + len - 1 - y + 1;
            if(h.get(1, tmp) != h.get(len - tmp + 1, len)) return 0;
        }
    }
    return 1;
}

inline void solve(){
    prepare(5e5);
    cin >> s;
    Hash h(s);
    vector<int> f = kmp(s);
    n = len(s);
    s = " " + s;
    int i = n;
    vector<int> can;
    while(i >= 1){
        can.push_back(f[i]);
        i = f[i];
    }
    reverse(all(can));
    int l = -1, r = len(can);
    while(r - l > 1){
        int mid = l + r >> 1;
        if(check(can[mid], h)) r = mid;
        else l = mid;
    }
    cout << (r < len(can) ? can[r] : n);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #define name "icpc"
    if(fopen(name".inp", "r")){
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    
    int o = 1; ///cin >> o;
    while(o --> 0) solve();
}