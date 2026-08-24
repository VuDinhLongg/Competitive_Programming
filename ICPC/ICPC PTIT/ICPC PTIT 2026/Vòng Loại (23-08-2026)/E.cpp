#include <bits/stdc++.h>
using namespace std;

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define len(x) (int)x.size()
#define int long long
#define mxn 1'000'007

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

int n, m, d[303][303];

void solve(){
	cin >> n >> m;
	fo(u, 1, n) fo(v, 1, n) d[u][v] = 1e9;
	DSU dsu(n);
	fo(i, 1, m){
		int u, v; cin >> u >> v;
		d[u][v] = 1;
		dsu.merge(u, v);
	}
	int res = 1e9;
	fo(i, 1, n) fo(j, 1, n) fo(k, 1, n){
		mini(d[i][j], d[i][k] + d[k][j]);
	}
	fo(i, 1, n) fo(j, 1, n) fo(k, 1, n) if(i != j and j != k and k != i){
		mini(res, d[i][j] + d[j][k] + d[k][i]);
	}
	cout << (res < 1e9 ? res : -1), el;
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	#define file "LonggVuz"
	if(fopen(file".inp", "r")){
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	}
	
	int o = 1; cin >> o;
	while(o --> 0) solve();
}