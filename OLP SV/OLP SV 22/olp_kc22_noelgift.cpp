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
#define mxn 100'007

struct DSU{
    vector<int> boss, sz, e;
    DSU(int n){
        boss.resize(n + 5);
        iota(begin(boss), end(boss), 0);
        sz.assign(n + 5, 1);
        e.assign(n + 5, 0);
    }
    int find(int u){
        while(u ^ boss[u]) u = boss[u] = boss[boss[u]];
    	return u;
    }
    bool merge(int u, int v){
        u = find(u); v = find(v);
        if(u == v){
        	++e[u];
        	return false;
        }
        if(sz[u] < sz[v]) swap(u, v);
        boss[v] = u;
        sz[u] += sz[v];
        e[u] += e[v] + 1;
        return true;
    }
    int size(int u){ return sz[find(u)]; }
    int edge(int u){ return e[find(u)]; }
    bool same(int u, int v){ return find(u) == find(v); }
};

inline void LonggVuz(){
    int n, m; cin >> n >> m;
    DSU dsu(n);
    rep(i, m){
    	int u, v; cin >> u >> v;
    	dsu.merge(u, v);
    }
    int res = 0;
    fo(u, 1, n) if(u == dsu.find(u)){
    	if(dsu.size(u) == 1) continue;
    	int add = dsu.size(u);
    	if(dsu.edge(u) < dsu.size(u)) --add;
    	dbg(u, add);
    	res += add;
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
