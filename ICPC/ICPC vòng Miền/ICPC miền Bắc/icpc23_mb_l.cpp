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
// #define int long long
#define mxn 5'000'007

int f[mxn], mod = 998244353;

inline void LonggVuz(){
	fo(i, 1, 5e6) f[i] = i;
	fo(i, 2, 5e6) if(f[i] == i){
		for(int j=i; j<=5e6; j+=i){
			f[j] -= f[j] / i;
		}
	}
	int a, b; cin >> a >> b;
	long long res = 0;
	fo(i, 1, b){
		int d = gcd(a, i);
		// res += ((__int128_t)1 * f[a] * f[i] * d / f[d]) % mod;
		res += (1ll * f[a] * f[i] / f[d] * d) % mod;
		res %= mod;
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(false) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
