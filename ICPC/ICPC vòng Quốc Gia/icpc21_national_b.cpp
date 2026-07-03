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
#define mxn 1'000'007

int n, m, used[55][55];
char a[55][55];

int dist(char u, char v){
	return min(abs(u - v), abs(abs(u - v) - 26));
}

int calc(set<pair<int, int>> &s){
	int res = 1e18;
	for(char c = 'A'; c <= 'Z'; ++c){
		int ans = 0;
		for(auto &[i, j] : s){
			ans += dist(c, a[i][j]);
		}
		mini(res, ans);
	}
	return res;
}

inline void LonggVuz(){
	cin >> n >> m;
	fo(i, 1, n) fo(j, 1, m){
		cin >> a[i][j];
	}
	int res = 0;
	fo(i, 1, n) fo(j, 1, m) if(!used[i][j]){
		dbg(i, j);
		set<pair<int, int>> s;
		s.insert({i, j}); used[i][j] = 1;
		s.insert({n - i + 1, j}); used[n - i + 1][j] = 1;
		s.insert({i, m - j + 1}); used[i][m - j + 1] = 1;
		s.insert({n - i + 1, m - j + 1}); used[n - i + 1][m - j + 1] = 1;
		res += calc(s);
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(false) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
