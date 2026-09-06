#include <bits/stdc++.h>
using namespace std;

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define rep(i, n) fo(i, 0, n - 1)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define int long long
#define mxn 100'007
#define ii pair<int, int>
#define fi first
#define se second

struct DSU{
    vector<int> boss, sz;
    DSU(int n){
        boss.resize(n + 5); iota(all(boss), 0); sz.assign(n + 5, 1);
    }
    int find(int u){
        return (u == boss[u] ? u : boss[u] = find(boss[u]));
    }
    bool merge(int u, int v){
        u = find(u); v = find(v);
        if(u == v) return false;
        if(sz[u] < sz[v]) swap(u, v);
        boss[v] = u; sz[u] += sz[v];
        return true;
    }
    int size(int u){ return sz[find(u)]; }
    bool same(int u, int v){ return find(u) == find(v); }
};

struct node{
	int u, v, w;
};

int n;
vector<ii> g[mxn];
vector<node> canh;

inline void solve(){
    cin >> n;
    fo(i, 2, n){
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
		canh.push_back({u, v, w});
    }
    sort(all(canh), [](node &x, node &y){
		return x.w < y.w;
	});
	DSU dsu(n);
	int res = 0;
	for(auto &[u, v, w] : canh){
		res += dsu.size(u) * dsu.size(v) * w;
		dsu.merge(u, v);
	}
	cout << res;
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