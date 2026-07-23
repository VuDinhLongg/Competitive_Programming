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

string s;
int k;

inline void LonggVuz(){
	cin >> s >> k;
	int n = len(s);
	s = string(1, 'z' + 1) + s + string(1, 'z' + 1);
	int pos = 1, d = 1;
	fo(i, 1, n){
		if(s[i] < s[pos]){
			pos = i;
			if(s[i - 1] < s[i + 1]) d = -1;
			else d = 1;
		}else if(s[i] == s[pos]){
			if(s[i - 1] < s[pos + d]){
				pos = i;
				d = -1;
			}
			if(s[i + 1] < s[pos + d]){
				pos = i;
				d = 1;
			}
		}
		dbg(i, pos, d);
	}
	fo(i, 1, k){
		cout << (i & 1 ? s[pos] : s[pos + d]);
	}
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
