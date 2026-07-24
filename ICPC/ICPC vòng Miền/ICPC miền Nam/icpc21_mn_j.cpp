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
#define int int16_t
#define mxn 5007

int n, m, u[mxn][mxn], d[mxn][mxn], l[mxn][mxn], r[mxn][mxn];
char a[mxn][mxn];

inline void LonggVuz(){
	cin >> n >> m;
	fo(i, 1, n) fo(j, 1, m){
		cin >> a[i][j];
	}
	fo(i, 1, n){
		fo(j, 1, m){
			if(a[i][j] == '1') l[i][j] = l[i][j - 1] + 1;
		}
		fd(j, m, 1){
			if(a[i][j] == '1') r[i][j] = r[i][j + 1] + 1;
		}
	}
	fo(j, 1, m){
		fo(i, 1, n){
			if(a[i][j] == '1') u[i][j] = u[i - 1][j] + 1;
		}
		fd(i, n, 1){
			if(a[i][j] == '1') d[i][j] = d[i + 1][j] + 1;
		}
	}
	int res = -1, x = 0, y = 0;
	fo(i, 1, n) fo(j, 1, m) if(a[i][j] == '1'){
		int k = min({l[i][j], r[i][j], u[i][j], d[i][j]}) - 1;
		if(maxi(res, k * 4 + 1)){
			x = i;
			y = j;
		}
	}
	cout << res, el;
	if(res != -1) cout << x << ' ' << y, el;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
