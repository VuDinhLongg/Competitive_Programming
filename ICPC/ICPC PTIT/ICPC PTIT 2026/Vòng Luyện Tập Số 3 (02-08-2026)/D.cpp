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

bool check(int x){
	return x % 6 == 0 or x % 10 == 0 or x % 15 == 0;
}

inline void LonggVuz(){
	int n; cin >> n;
	vector<int> a(n + 5);
	a[1] = 6;
	a[2] = 10;
	a[3] = 15;
	int x = 16;
	fo(i, 4, n){
		while(!check(x)) ++x;
		a[i] = x;
		++x;
	}
	fo(i, 1, n) cout << a[i] << ' ';
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}