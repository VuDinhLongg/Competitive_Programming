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

struct Combinatoric{
	int n;
	vector<int> fact, invfact;
	Combinatoric(int _n){
		n = _n;
		fact.resize(n + 5);
		invfact.resize(n + 5);
		fact[0] = 1;
		for(int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % mod;
		invfact[n] = inverse(fact[n]);
		for(int i = n; i >= 1; --i) invfact[i - 1] = invfact[i] * i % mod;
	}
	int Pow(int a, int n){
		int r = 1; a %= mod;
		for(; n; n >>= 1, a = a * a % mod) if(n & 1) r = r * a % mod;
		return r;
	}
	int inverse(int a){ return Pow(a, mod - 2); }
	int C(int n, int k){
		if(n < 0 or k < 0 or n < k) return 0;
		return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
	}
	int Euler(int n, int k){ return C(n + k - 1, n); }
} Calc(1e6) ;

int n, m, a, b;

int Pow(int a, int n, int m = 1e9 + 7){
	int r = 1; a %= m;
	for(; n; n >>= 1, a = a * a % m) if(n & 1) r = r * a % m;
	return r;
}

inline void LonggVuz(){
	cin >> n >> m >> a >> b;
	int res = 0;
	fo(len, 1, n - 1) if(m >= len){
		int ans = Calc.C(m - 1, len - 1) * Calc.C(n - 2, len - 1) % mod * Calc.fact[len - 1] % mod;
		int rem = n - 1 - len;
		if(rem){
			ans = ans * Pow(n, rem - 1) % mod;
			ans = ans * (len + 1) % mod;
			ans = ans * Pow(m, rem) % mod;
		}
		dbg(len, ans);
		res = (res + ans) % mod;
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}