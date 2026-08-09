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

int a, x, m;

int Pow(int a, int n, int m = 1e9 + 7){
	int r = 1; a %= m;
	for(; n; n /= 2, a = a * a % m) if(n & 1) r = r * a % m;
	return r;
}

int calc(int a, int x){
	if(x == 0) return 1 % m;
	if(x & 1){
		int res = calc(a, x / 2);
		res = res * (Pow(a, (x + 1) / 2, m) + 1) % m;
		return res;
	}
	return (calc(a, x - 1) + Pow(a, x, m)) % m;
}

inline void LonggVuz(){
	cin >> a >> x >> m;
	--x;
	cout << calc(a, x);
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}