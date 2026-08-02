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

int Pow(int a, int n, int m = 1e9 + 7){
	int r = 1; a %= m;
	for(; n; n >>= 1, a = a * a % m) if(n & 1) r = r * a % m;
	return r;
}

inline void LonggVuz(){
	int n; cin >> n;
	if(n == 1) ret(0);
	int res = Pow(10, n);
	int sub1 = Pow(9, n);
	int sub2 = Pow(9, n);
	int add = Pow(8, n);
	cout << (res - sub1 - sub2 + add + mod * mod) % mod;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}