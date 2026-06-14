/*======================
   Author : @LonggVuz
======================*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define orz(...) 2005
#endif

#define el cout << '\n'
#define all(x) begin(x), end(x)
#define fix(x) fixed << setprecision(x)
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 1'000'007

#define pii pair<int, int>
#define pip pair<int, pii>
#define ppi pair<pii, int>
#define fi first
#define se second
#define bit(n, i) ((n) >> (i) & 1)

int n, dp[2][mxn], ans, b;
vector<pii> ke[mxn];

void dfs(int u, int p = 0){
    for(auto &[v, w] : ke[u]) if(v != p){
        dfs(v, u);
        if(bit(w, b)){
            ans += dp[0][v];
            dp[0][u] += dp[1][v];
            dp[1][u] += dp[0][v];
            ans += 1;
            dp[1][u] += 1;
        }else{
            ans += dp[1][v];
            dp[0][u] += dp[0][v];
            dp[1][u] += dp[1][v];
            dp[0][u] += 1;
        }
    }
    // debug(u, dp[0][u], dp[1][u]);
}

void cal(int u, int p = 0){
    // debug(u, dp[0][u], dp[1][u]);
    for(auto &[v, w] : ke[u]) if(v != p){
        if(bit(w, b)){
            ans += (dp[0][u] - dp[1][v] + 1);
            dp[0][v] = dp[1][u] - 1;
            dp[1][v] = dp[0][u] + 1;
        }else{
            ans += (dp[1][u] - dp[1][v]);
            dp[0][v] = dp[0][u];
            dp[1][v] = dp[1][u];
        }
        cal(v, u);
    }
}

inline void LonggVuz(){
    cin >> n;
    fo(i, 2, n){
        int x, y, w; cin >> x >> y >> w;
        ke[x].push_back({y, w});
        ke[y].push_back({x, w});
    }
    int res = 0;
    fo(i, 0, 25){
        fo(u, 1, n) dp[0][u] = dp[1][u] = 0;
        ans = 0;
        b = i;
        dfs(1);
        cal(1);
        res += ans * (1 << i);
    }
    cout << res / 2;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}