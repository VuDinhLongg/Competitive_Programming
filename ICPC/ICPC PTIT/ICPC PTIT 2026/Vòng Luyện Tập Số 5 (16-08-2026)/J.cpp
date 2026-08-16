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

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 200'007
#define ai3 array<int, 3>
#define ai4 array<int, 4>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, d[mxn], id[mxn];
vector<ai3> g[mxn];

inline void LonggVuz(){
	cin >> n >> m;
	fo(i, 1, m){
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({v, w, i});
		g[v].push_back({u, w, i});
	}
	fo(u, 2, n) d[u] = 1e18;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({d[1], 1});
	while(len(q)){
		auto [cur, u] = q.top(); q.pop();
		if(cur > d[u]) continue;
		for(auto &[v, w, i] : g[u]) if(mini(d[v], d[u] + w)){
			id[v] = i;
			q.push({d[v], v});
		}
	}
	fo(u, 2, n) cout << id[u] << ' ';
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}