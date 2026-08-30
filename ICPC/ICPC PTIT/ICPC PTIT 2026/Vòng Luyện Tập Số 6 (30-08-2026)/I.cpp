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
#define mxn 50'007

int n, c[mxn], dp[mxn], res;
vector<int> g[mxn];
multiset<int> ms1, ms2;

void dfs1(int u, int p){
	dp[u] = c[u];
	for(int &v : g[u]) if(v != p){
		dfs1(v, u);
		dp[u] += dp[v];
	}
}

void dfs2(int u, int p){
	if(u > 1) ms1.insert(dp[u]);
	for(int &v : g[u]) if(v != p){
		if(dp[v] * 2 == dp[1]){
			mini(res, dp[v]);
		}
		if((dp[1] + dp[v]) % 2 == 0){
			int x = (dp[1] + dp[v]) / 2;
			if(ms1.find(x) != ms1.end()){
				int tmp = dp[1] - x;
				if(tmp >= dp[v]) mini(res, tmp - dp[v]);
			}
		}
		{
			int x = dp[v] * 2;
			if(ms1.find(x) != ms1.end()){
				int tmp = dp[1] - x;
				if(tmp <= dp[v]) mini(res, dp[v] - tmp);
			}
		}
		{
			int x = dp[1] - dp[v];
			if(ms1.find(x) != ms1.end()){
				int tmp = x - dp[v];
				if(tmp <= dp[v]) mini(res, dp[v] - tmp);
			}
		}
		{
			if(ms2.find(dp[v]) != ms2.end()){
				int tmp = dp[1] - dp[v] * 2;
				if(tmp <= dp[v]) mini(res, dp[v] - tmp);
			}
		}
		{
			int x = dp[1] - dp[v] * 2;
			if(ms2.find(x) != ms2.end()){
				int tmp = x;
				if(tmp <= dp[v]) mini(res, dp[v] - tmp);
			}
		}
		if((dp[1] - dp[v]) % 2 == 0){
			int x = (dp[1] - dp[v]) / 2;
			if(ms2.find(x) != ms2.end()){
				if(dp[v] <= x) mini(res, x - dp[v]);
			}
		}
		dfs2(v, u);
	}
	if(u > 1) ms1.erase(ms1.find(dp[u]));
	ms2.insert(dp[u]);
}

inline void LonggVuz(){
	cin >> n;
	fo(i, 1, n) cin >> c[i];
	fo(i, 2, n){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1, 0);
	res = 1e18;
	dfs2(1, 0);
	cout << (res < 1e18 ? res : -1), el;
	fo(u, 1, n) g[u].clear();
	ms1.clear();
	ms2.clear();
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "LonggVuz"
	if(fopen(name".inp", "r")){
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	
	signed o_o = 1; if(1) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}