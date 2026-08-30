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
#define rep(i, n) fo(i, 0, n - 1)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define int long long
#define mxn 1'000'007

int n, m, vis[2005][2005];
vector<int> g[2005];

int calc(int s){
	queue<int> q;
	q.push(s);
	vis[s][s] = 1;
	while(q.size()){
		int u = q.front(); q.pop();
		for(int &v : g[u]) if(!vis[s][v]){
			vis[s][v] = 1;
			q.push(v);
		}
	}
	int res = 0;
	fo(u, 1, n) res += vis[s][u];
	return res;
}

inline void LonggVuz(){
	cin >> n >> m;
	fo(i, 1, m){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
	}
	int res = 0;
	fo(u, 1, n) res += calc(u);
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "LonggVuz"
	if(fopen(name".inp", "r")){
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}