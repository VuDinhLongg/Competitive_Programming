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
#define mxn 10'000'007

int mpf[mxn], cnt[mxn];

inline void LonggVuz(){
	fo(i, 2, 1e7) if(mpf[i] == 0){
		mpf[i] = i;
		for(int j=1ll*i*i; j<=1e7; j+=i){
			if(mpf[j] == 0) mpf[j] = i;
		}
	}
	
	int n; cin >> n;
	int res = 0, x;
	rep(i, n){
		cin >> x;
		int r = 1;
		while(x > 1){
			int p = mpf[x];
			r *= p;
			while(x % p == 0) x /= p;
		}
		res += cnt[r];
		++cnt[r];
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(false) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
