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

int dp[mxn][5];

inline void LonggVuz(){
	string s;
	while(cin >> s){
		if(s == "$") break;
		int n = len(s);
		s = " " + s;
		fo(i, 1, n){
			fo(j, 1, 4) dp[i][j] = dp[i - 1][j];
			if(s[i] == 'I') dp[i][1] += 1;
			if(i >= 2){
				if(s[i] == 'C') dp[i][2] += dp[i - 2][1], dp[i][4] += dp[i - 2][3];
				if(s[i] == 'P') dp[i][3] += dp[i - 2][2];
			}
		}
		cout << dp[n][4], el;
		fo(i, 1, n) fo(j, 1, 4) dp[i][j] = 0;
	}
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(false) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
