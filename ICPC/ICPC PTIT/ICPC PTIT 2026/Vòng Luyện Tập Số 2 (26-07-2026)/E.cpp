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
#define mxn 1'000'007

const int mod = 1e9 + 7;

int n, k, a[mxn], pre[mxn], suf[mxn];

int sum(int l, int r){
	return ((l + r) * (r - l + 1) / 2) % mod;
}

inline void LonggVuz(){
	cin >> n >> k;
	fo(i, 1, n) cin >> a[i];
	fo(i, 1, n){
		fo(j, 1, i - 1){
			if(a[j] > a[i]) ++pre[i];
		}
		fo(j, i + 1, n){
			if(a[j] > a[i]) ++suf[i];
		}
	}
	int res = 0;
	fo(i, 1, n){
		dbg(i, pre[i], suf[i]);
		res += pre[i] * sum(1, k) % mod + suf[i] * sum(1, k - 1) % mod;
		res %= mod;
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}