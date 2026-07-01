// Accepted on Subtask 1 + 2 (80%)
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
#define len(x) (int)(x).size()
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 200'007

const int mod = 1e9 + 7;

int n, q, a[mxn];
vector<int> ke[mxn];
int h[mxn], dad[mxn][20], dp[mxn][20];

void dfs(int u, int p = 0){
	for(int &v : ke[u]) if(v != p){
		h[v] = h[u] + 1;
		dad[v][0] = u;
		dp[v][0] = a[u];
		fo(k, 1, 18){
			dp[v][k] = max(dp[v][k - 1], dp[dad[v][k - 1]][k - 1]);
			dad[v][k] = dad[dad[v][k - 1]][k - 1];
		}
		dfs(v, u);
	}
}

pair<int, int> lca(int u, int v){
	if(h[u] < h[v]) swap(u, v);
	int res = max(a[u], a[v]);
	fd(i, 18, 0) if((h[u] - h[v]) >> i & 1){
		maxi(res, dp[u][i]);
		u = dad[u][i];
	}
	if(u == v) return {res, u};
	fd(i, 18, 0) if(dad[u][i] != dad[v][i]){
		maxi(res, max(dp[u][i], dp[v][i]));
		u = dad[u][i];
		v = dad[v][i];
	}
	maxi(res, dp[u][0]);
	return {res, dad[u][0]};
}

int dist(int u, int v){
	return h[u] + h[v] - h[lca(u, v).second] * 2;
}

namespace sub1{
	bool check(){
		return n <= 200;
	}
	void solve(){
		dfs(1);
		int res = 0;
		fo(x, 1, n) fo(y, x + 1, n) fo(z, y + 1, n){
			int mx = max({lca(x, y).first, lca(y, z).first, lca(z, x).first});
			if(mx == q){
				res += dist(x, y) + dist(y, z) + dist(z, x);
				res %= mod;
			}
		}
		cout << res;
	}
}

namespace sub2{
	bool check(){
		if(q != 2) return 0;
		fo(i, 1, n) if(a[i] > 2) return 0;
		return 1;
	}
	int res, sz[mxn], sub, cnt;
	void dfs(int u, int p = 0){
		for(int &v : ke[u]) if(v != p){
			dfs(v, u);
			res += (n - sz[v]) * sz[v];
			res %= mod;
			sz[u] += sz[v];
		}
		++sz[u];
	}
	void dfs2(int u, int p = 0){
		++cnt;
		for(int &v : ke[u]) if(v != p and a[v] == 1){
			dfs2(v, u);
		}
	}
	void dfs3(int u, int p = 0){
		a[u] = 2;
		for(int &v : ke[u]) if(v != p and a[v] == 1){
			dfs3(v, u);
			sub += (cnt - sz[v]) * sz[v];
			sub %= mod;
			sz[u] += sz[v];
		}
		++sz[u];
	}
	void solve(){
		dfs(1);
		res *= (n - 2);
		res %= mod;
		dbg(res);
		fo(u, 1, n) sz[u] = 0;
		fo(u, 1, n) if(a[u] == 1){
			cnt = 0;
			dfs2(u);
			sub = 0;
			dfs3(u);
			dbg(u, cnt, sub);
			res -= sub * (cnt - 2);
			res %= mod;
		}
		if(res < 0) res += mod;
		cout << res;
	}
}

namespace sub3{
	bool check(){
		return 1;
	}
	void solve(){
		
	}
}

inline void LonggVuz(){
	cin >> n >> q;
	fo(i, 1, n) cin >> a[i];
	fo(i, 2, n){
		int u, v; cin >> u >> v;
		ke[u].push_back(v);
		ke[v].push_back(u);
	}
	if(sub1::check()) sub1::solve();
	else if(sub2::check()) sub2::solve();
	else sub3::solve();
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(false) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
