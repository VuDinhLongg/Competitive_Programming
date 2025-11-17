// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LonggVuz
#include <LonggVuz.h>
#else
#define debug(...)
#endif

template<class X, class Y> bool maxi(X &a, const Y &b){ return b > a ? a = b, 1 : 0; }
template<class X, class Y> bool mini(X &a, const Y &b){ return b < a ? a = b, 1 : 0; }

#define el cout << '\n'
#define fup(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define fdn(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int32_t i=a; i<=b; i++)
#define fd(i, a, b) for(int32_t i=a; i>=b; i--)
#define out(x) return void(cout << (x))
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define dub double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e5 + 7;

#define pii pair<int, int>
#define pip pair<int, pii>
#define ppi pair<pii, int>
#define fi first
#define se second

struct dsu{
    vec<int> par, sz;
    dsu(int n){
        par.resize(n + 5); iota(all(par), 0); sz.resize(n + 5, 1);
    }
    int get(int u){
        return (u == par[u]) ? (u) : (par[u] = get(par[u]));
    }
    bool uni(int u, int v){
        u = get(u); v = get(v);
        if(u == v) return 0;
        if(u > v) swap(u, v);
        par[v] = u; sz[u] += sz[v];
        return 1;
    }
    int size(int u){
        return sz[get(u)];
    }
    bool same(int u, int v){
        return get(u) == get(v);
    }
};

int n, q, dp[20][mxn], vis[mxn];
vec<pii> ke[mxn];

int p[20][mxn], h[mxn];

void dfs(int u, int par = 0){
    vis[u] = 1;
    for(auto &[v, w] : ke[u]) if(v != par){
        h[v] = h[u] + 1;
        p[0][v] = u;
        dp[0][v] = -w;
        for(int k=1; 1<<k <= n; k++){
            p[k][v] = p[k - 1][p[k - 1][v]];
            dp[k][v] = dp[k - 1][v] + dp[k - 1][p[k - 1][v]];
        }
        dfs(v, u);
    }
}

int lca(int u, int v){
    int ok = 1;
    if(h[u] < h[v]){
        swap(u, v);
        ok = -1;
    }
    int res = 0;
    int d = h[u] - h[v];
    fo(i, 0, 19) if(d >> i & 1){
        res += dp[i][u] * ok;
        u = p[i][u];
    }
    if(u == v) return res;
    fd(i, 19, 0) if(p[i][u] != p[i][v]){
        res += dp[i][u] * ok;
        res -= dp[i][v] * ok;
        u = p[i][u];
        v = p[i][v];
    }
    return res + (dp[0][u] * ok) - (dp[0][v] * ok);
}

inline void LonggVuz(){
    cin >> n >> q;
    dsu d(n);
    vec<pii> tv;
    fo(i, 1, q){
        char t; cin >> t;
        if(t == '!'){
            int x, y, w; cin >> x >> y >> w;
            if(d.uni(x, y)){
                ke[x].pub({y, w});
                ke[y].pub({x, -w});
            }
        }else{
            int x, y; cin >> x >> y;
            if(d.same(x, y)) tv.pub({x, y});
            else tv.pub({0, 0});
        }
    }
    fo(i, 1, n) if(!vis[i]){
        dfs(d.get(i));
    }
    for(auto &[x, y] : tv){
        if(x and y) cout << lca(x, y), el;
        else cout << "UNKNOWN", el;
    }
    fo(i, 1, n){
        h[i] = vis[i] = 0;
        fo(j, 0, 19) dp[j][i] = p[j][i] = 0;
        ke[i].clear();
    }
}

signed main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    
    signed orz = 1; if(1) cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
