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

int n, m, a[101], b[101];

bool check(int day){
	int res = m;
	fo(i, 1, n){
		int cnt = day - day / (b[i] + 1);
		res -= cnt * a[i];
		if(res <= 0) return 1;
	}
	return 0;
}

inline void LonggVuz(){
	cin >> n >> m;
	fo(i, 1, n) cin >> a[i] >> b[i];
	int l = 0, r = 1e18;
	while(r - l > 1){
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout << r;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(false) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
