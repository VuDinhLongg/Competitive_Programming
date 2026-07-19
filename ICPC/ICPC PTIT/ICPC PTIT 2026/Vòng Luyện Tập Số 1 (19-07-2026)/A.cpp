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

int remain(string &s, int d){
	int r = 0;
	for(char &c : s) r = (r * 10 + c - '0') % d;
	return r;
}

inline void LonggVuz(){
	string s; cin >> s;
	int r7 = remain(s, 7);
	int r13 = remain(s, 13);
	if(r7 == 0 and r13 == 0) ret("Both");
	if(r7 != 0 and r13 == 0) ret("Div 13");
	if(r7 == 0 and r13 != 0) ret("Div 7");
	ret("None");
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(1) cin >> o_o;
	fo(c_c, 1, o_o) yay(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
