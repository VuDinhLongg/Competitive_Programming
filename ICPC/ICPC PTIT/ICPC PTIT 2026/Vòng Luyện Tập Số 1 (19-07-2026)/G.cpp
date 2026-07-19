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
#define int long long
#define mxn 100'007
#define ai3 array<int, 3>
#define ai4 array<int, 4>
#define pii pair<int, int>
#define fi first
#define se second

int n, c[mxn];
vector<pii> g[mxn];

void dfs(int u, int p, int pre = 0){
	int col = 0;
	for(auto &[v, i] : g[u]) if(v != p){
		c[i] = ++col;
		if(c[i] == pre) c[i] = ++col;
		dfs(v, u, c[i]);
	}
}

inline void LonggVuz(){
	cin >> n;
	fo(i, 2, n){
		int u, v; cin >> u >> v;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}
	dfs(1, 0);
	int k = 0;
	fo(i, 2, n) maxi(k, c[i]);
	cout << k, el;
	fo(i, 2, n) cout << c[i] << ' ';
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) yay(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
