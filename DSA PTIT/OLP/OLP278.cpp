// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LonggVuz
#include <LonggVuz.h>
#else
#define debug(...)
#define print(...)
#endif

template<class X, class Y> bool maxi(X &a, const Y &b){ return b > a ? a = b, 1 : 0; }
template<class X, class Y> bool mini(X &a, const Y &b){ return b < a ? a = b, 1 : 0; }

#define el cout << '\n'
#define fup(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define fdn(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
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

#define pii pair<int, int>
#define pip pair<int, pii>
#define ppi pair<pii, int>
#define fi first
#define se second

int n, q, p[20][mxn], f[20][mxn], h[mxn];
vec<pii> ke[mxn];

void dfs(int u, int par = 0){
    for(auto &[v, w] : ke[u]) if(v != par){
        h[v] = h[u] + 1;
        p[0][v] = u;
        f[0][v] = w;
        for(int k=1; 1<<k <= n; ++k){
            p[k][v] = p[k - 1][p[k - 1][v]];
            f[k][v] = max(f[k - 1][v], f[k - 1][p[k - 1][v]]);
        }
        dfs(v, u);
    }
}

int lca(int u, int v){
    if(h[u] < h[v]) swap(u, v);
    int res = 0;
    int delta = h[u] - h[v];
    fd(i, 19, 0) if(delta >> i & 1){
        maxi(res, f[i][u]);
        u = p[i][u];
    }
    if(u == v) return res;
    fd(i, 19, 0) if(p[i][u] != p[i][v]){
        maxi(res, max(f[i][u], f[i][v]));
        u = p[i][u];
        v = p[i][v];
    }
    maxi(res, max(f[0][u], f[0][v]));
    return res;
}

inline void LonggVuz(){
    cin >> n >> q;
    dsu d(n);
    vec<pii> tv;
    fo(i, 1, q){
        int t, u, v; cin >> t >> u >> v;
        if(t == 1){
            if(d.uni(u, v)){
                ke[u].pub({v, i});
                ke[v].pub({u, i});
            }
        }else{
            if(d.same(u, v)) tv.pub({u, v});
            else tv.pub({0, 0});
        }
    }
    fo(i, 1, n) if(h[i] == 0){
        h[i] = 1;
        dfs(i);
    }
    for(auto &[u, v] : tv){
        if(u and v) cout << lca(u, v), el;
        else cout << -1, el;
    }
    fo(i, 1, n){
        ke[i].clear();
        h[i] = 0;
        fo(j, 0, 19) p[j][i] = f[j][i] = 0;
    }
}

signed main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    
    signed hehe = 1; if(1) cin >> hehe;
    for(signed hihi = 1; hihi <= hehe; ++hihi){
        print(hihi);
        LonggVuz();
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
