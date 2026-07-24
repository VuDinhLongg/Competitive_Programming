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

int n, a[mxn], l[mxn], r[mxn];
string s;

int calc(char c){
	fo(i, 1, n) a[i] = (s[i] == c);
	{
		int pos = 0;
		fo(i, 1, n){
			l[i] = pos;
			if(a[i]) pos = i;
		}
	}
	{
		int pos = n + 1;
		fd(i, n, 1){
			r[i] = pos;
			if(a[i]) pos = i;
		}
	}
	int res = 0;
	fo(i, 1, n) if(a[i]) res += 1ll * (i - l[i]) * (r[i] - i);
	return res;
}

inline void LonggVuz(){
	cin >> s;
	n = len(s);
	s = " " + s;
	int res = 0;
	for(char c = 'a'; c <= 'z'; ++c){
		res += calc(c);
	}
	cout << res, el;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(1) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
