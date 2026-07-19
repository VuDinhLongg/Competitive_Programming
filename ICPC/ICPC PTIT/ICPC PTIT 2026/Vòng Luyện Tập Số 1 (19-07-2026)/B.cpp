/*======================
   Author : @LonggVuz
======================*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define yay(...) 2005
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

int mu(int a, int n){
	int r = 1;
	fo(i, 1, n) r *= a;
	return r;
}

inline void LonggVuz(){
	int n; cin >> n;
	fo(a, 1, 37) fo(b, 1, 25) if(mu(3, a) + mu(5, b) == n){
		cout << a << ' ' << b;
		return;
	}
	ret(-1);
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) yay(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
