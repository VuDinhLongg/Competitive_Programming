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
#define fix(x) fixed << setprecision(x)
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 300'007

int n, m, b[mxn], f[mxn], dp[mxn];

int dist(int u, int v){
	if(u > v) return v + m - u;
	return v - u;
}

int calc(int x){
	int res = 0;
	fo(i, 2, n){
		int add = min(dist(b[i - 1], b[i]), dist(x, b[i]) + 1);
		res += add;
	}
	return res;
}

inline void LonggVuz(){
    cin >> n >> m;
    fo(i, 1, n) cin >> b[i];
    fo(i, 2, n){
    	int l = b[i - 1];
    	int r = b[i];
    	if(l > r) r += m;
    	++dp[l + 2];
    	--dp[r + 1];
    	f[r + 1] -= r - l - 1;
    }
    fo(i, 1, m * 2) dp[i] += dp[i - 1];
    fo(i, 0, m * 2) dp[i] += f[i];
    fo(i, 1, m * 2) dp[i] += dp[i - 1];
    rep(i, m) dp[i] += dp[i + m];
    int idx = 0;
    rep(i, m) if(dp[i] > dp[idx]) idx = i;
    cout << calc(idx);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
