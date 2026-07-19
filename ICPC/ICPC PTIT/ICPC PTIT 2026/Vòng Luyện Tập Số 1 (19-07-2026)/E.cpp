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

const int mod = 1e9 + 7;

int n, m, bad[mxn], dp[mxn];

inline void LonggVuz(){
	cin >> n >> m;
	fo(i, 1, m){
		int x; cin >> x;
		bad[x] = 1;
	}
	dp[0] = 1;
	fo(i, 1, n) if(!bad[i]){
		dp[i] = dp[i - 1];
		if(i > 1) dp[i] += dp[i - 2];
		dp[i] %= mod;
	}
	cout << dp[n];
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) yay(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
