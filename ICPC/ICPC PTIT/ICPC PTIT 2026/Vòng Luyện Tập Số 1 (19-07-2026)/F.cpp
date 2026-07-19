/*======================
   Author : @LonggVuz
======================*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define yay(...) 2005
#endif

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
// #define int long long
#define mxn 5007

int n, vis[mxn], d[mxn], uu, vv, root, mx;
vector<int> g[mxn];
pair<int, int> e[mxn];

bool check(int u, int v){
	return !((u == uu and v == vv) or (u == vv and v == uu));
}

void dfs(int u, int p){
	if(maxi(mx, d[u])) root = u;
	vis[u] = 1;
	for(int &v : g[u]) if(v != p and check(u, v)){
		d[v] = d[u] + 1;
		dfs(v, u);
	}
}

int calc(int idx){
	uu = e[idx].first;
	vv = e[idx].second;
	int res = 0;
	fo(u, 1, n) vis[u] = 0;
	fo(u, 1, n) if(!vis[u]){
		d[u] = 0;
		mx = 0;
		dfs(u, 0);
		d[root] = 0;
		mx = 0;
		dfs(root, 0);
		maxi(res, (mx + 1) / 2);
	}
	return res;
}

inline void LonggVuz(){
	cin >> n;
	fo(i, 2, n){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		e[i - 1] = {u, v};
	}
	int res = 1e9;
	fo(i, 1, n - 1) mini(res, calc(i));
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) yay(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
