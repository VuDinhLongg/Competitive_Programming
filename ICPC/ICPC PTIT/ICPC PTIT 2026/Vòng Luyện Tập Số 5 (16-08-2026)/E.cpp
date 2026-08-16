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
#define mxn 2'000'007

int n, l[mxn], r[mxn], res;
vector<int> dp[mxn];

int calc(vector<int> &a, vector<int> &b){
	int res = 0, i = len(a) - 1;
	fd(j, len(b) - 1, 0){
		while(i >= 0 and a[i] > b[j]) --i;
		res += len(a) - 1 - i;
	}
	return res;
}

void dfs(int u, int p){
	if(l[u] and r[u]){
		dfs(l[u], u);
		dfs(r[u], u);
		int cnt1 = calc(dp[l[u]], dp[r[u]]);
		int cnt2 = calc(dp[r[u]], dp[l[u]]);
		res += min(cnt1, cnt2);
		int i = 0, j = 0;
		while(i < len(dp[l[u]]) and j < len(dp[r[u]])){
			if(dp[l[u]][i] < dp[r[u]][j]) dp[u].push_back(dp[l[u]][i++]);
			else dp[u].push_back(dp[r[u]][j++]);
		}
		while(i < len(dp[l[u]])) dp[u].push_back(dp[l[u]][i++]);
		while(j < len(dp[r[u]])) dp[u].push_back(dp[r[u]][j++]);
		dp[l[u]].clear();
		dp[r[u]].clear();
	}else{
		dp[u].push_back(u);
	}
	dbg(u, res);
}

inline void LonggVuz(){
	cin >> n;
	fo(i, 1, n * 2 - 2){
		int u, v; char c; cin >> u >> v >> c;
		if(c == 'L') l[u] = v;
		else r[u] = v;
	}
	int root = n + 1;
	dfs(root, 0);
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}