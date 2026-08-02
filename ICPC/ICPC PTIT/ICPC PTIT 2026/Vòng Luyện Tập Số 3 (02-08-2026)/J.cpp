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
#define mxn 100'007
#define mask(n) (1ll << (n))
#define bit(n, i) ((n) >> (i) & 1)
#define one(n) __builtin_popcountll(n)
#define clz(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctzll(n)

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

int n, k, p[mxn];

inline void LonggVuz(){
	cin >> n >> k;
	int res = 0;
	fo(i, 1, n){
		int x = i, cnt = 0;
		while(x > 1){
			++cnt;
			int tmp = p[x];
			x /= tmp;
			if(tmp == p[x]){
				cnt = -1; break;
			}
		}
		if(cnt == -1) continue;
		int ans = Calc.C(n / i + k - 1, k);
		if(cnt & 1) res = (res - ans) % mod;
		else res = (res + ans) % mod;
	}
	if(res < 0) res += mod;
	cout << res, el;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	fo(i, 2, 1e5) if(p[i] == 0){
		p[i] = i;
		for(int j=1ll*i*i; j<=1e5; j+=i) if(p[j] == 0) p[j] = i;
	}
	
	signed o_o = 1; if(1) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}