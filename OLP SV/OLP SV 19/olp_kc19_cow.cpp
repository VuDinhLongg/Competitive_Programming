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
#define mxn 1'000'007

int n, a, b, x[101], y[101], r[101];

bool check(int len){
	fo(i, 1, n){
		int d1 = len + r[i];
		int d2 = (a - x[i]) * (a - x[i]) + (b - y[i]) * (b - y[i]);
		if(d1 * d1 >= d2) return 0;
	}
	return 1;
}

inline void LonggVuz(){
    cin >> n >> a >> b;
    fo(i, 1, n) cin >> x[i] >> y[i] >> r[i];
    int l = 0, r = 3e9;
    while(r - l > 1){
    	int mid = l + r >> 1;
    	if(check(mid)) l = mid;
    	else r = mid;
    }
    cout << l;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
