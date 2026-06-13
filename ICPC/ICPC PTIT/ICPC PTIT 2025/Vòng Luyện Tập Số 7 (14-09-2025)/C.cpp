// LonggVuz
#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<LonggVuz.h>
#else
#define debug(...)
#endif

#define el cout << '\n'
#define inc(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define dec(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int32_t i=a; i<=b; i++)
#define fd(i, a, b) for(int32_t i=a; i>=b; i--)
#define out(x) return void(cout << (x));
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define float double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e5 + 7;

#define pe pair<int, int>
#define fi first
#define se second
#define bit(n, i) ((n) >> (i) & 1)
int n, q, a[mxn], p[18][mxn], d[mxn], dp[mxn];
vec<int> ke[mxn];

void dfs(int u){
    dp[u] += a[u] * a[u];
    for(int &v : ke[u]){
        d[v] = d[u] + 1;
        dp[v] += dp[u];
        for(int k=1; 1<<k <= n; k++){
            p[k][v] = p[k - 1][p[k - 1][v]];
        }
        dfs(v);
    }
}

pe lca(int u, int v){
    fd(i, 17, 0) if(p[i][u] != p[i][v]){
        u = p[i][u];
        v = p[i][v];
    }
    return {u, v};
}

void LonggVuz(){
    cin >> n >> q;
    fo(i, 1, n){
        cin >> a[i];
    }
    fo(i, 2, n){
        cin >> p[0][i];
        ke[p[0][i]].pub(i);
    }
    d[1] = 1;
    dfs(1);
    while(q--){
        int x, y; cin >> x >> y;
        auto [u, v] = lca(x, y);
        if(u == v){
            cout << dp[u], el;
        }else{
            int res = dp[p[0][u]];
            while(x != p[0][u] and y != p[0][v]){
                res += a[x] * a[y];
                x = p[0][x];
                y = p[0][y];
            }
            cout << res, el;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; if(false) cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
