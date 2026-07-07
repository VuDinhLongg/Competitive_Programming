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

int n, m, a[1005][1005], f[4][1005];

inline void LonggVuz(){
	cin >> n >> m;
	fo(i, 1, n){
		f[0][i] = 1e18;
		f[1][i] = -1e18;
	}
	fo(j, 1, m){
		f[2][j] = 1e18;
		f[3][j] = -1e18;
	}
	fo(i, 1, n) fo(j, 1, m){
		cin >> a[i][j];
		mini(f[0][i], a[i][j]);
		maxi(f[1][i], a[i][j]);
		mini(f[2][j], a[i][j]);
		maxi(f[3][j], a[i][j]);
	}
	int res = 0;
	fo(i, 1, n) fo(j, 1, m){
		if(f[0][i] == f[1][i] and f[2][j] == f[3][j]) ++res;
	}
	cout << res, el;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(1) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
