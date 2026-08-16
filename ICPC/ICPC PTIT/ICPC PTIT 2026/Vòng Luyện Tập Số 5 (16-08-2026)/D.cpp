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
#define fo(i, a, b) for(int64_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 1'000'007
#define ldb long double

const ldb eps = 1e-9;

int a, b;

ldb calc(int x){
	ldb res = x * b + (ldb)a / sqrtl(x + 1);
	return res;
}

inline void LonggVuz(){
	cin >> a >> b;
	cout << fixed << setprecision(6);
	int l = 0, r = (int)8e18 / b;
	while(r - l > 2){
		int m1 = l + (r - l) / 3;
		int m2 = r - (r - l) / 3;
		if(calc(m1) >= calc(m2)) l = m1;
		else r = m2;
	}
	int res = l;
	fo(i, l + 1, r) if(calc(res) >= calc(i)) res = i;
	cout << calc(res);
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}