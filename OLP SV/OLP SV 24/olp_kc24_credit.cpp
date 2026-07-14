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
#define ai3 array<int, 3>
#define ai4 array<int, 4>
#define pii pair<int, int>
#define fi first
#define se second

int n, c;
pii a[mxn];

bool check(int mid){
	int res = a[1].se;
	fo(i, 2, n){
	    if(res >= c) return 1;
		if(a[i].fi - a[i - 1].fi <= mid){
			res += a[i].se;
		}else{
			res = a[i].se;
		}
	}
	return res >= c;
}

inline void LonggVuz(){
	cin >> n >> c;
	fo(i, 1, n) cin >> a[i].fi;
	fo(i, 1, n) cin >> a[i].se;
	sort(a+1, a+n+1);
	int l = -1, r = 1e9;
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
