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

int n, a, b;
string s;

void rotate(){
	char c = s[1];
	fo(i, 1, n - 1) s[i] = s[i + 1];
	s[n] = c;
}

inline void LonggVuz(){
	cin >> n >> a >> b >> s;
	s = " " + s;
	int res = 1e18;
	fo(i, 0, n - 1){
		dbg(s);
		int l = 1, r = n;
		int ans = a * i;
		while(l < r){
			if(s[l] != s[r]) ans += b;
			++l; --r;
		}
		mini(res, ans);
		rotate();
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}