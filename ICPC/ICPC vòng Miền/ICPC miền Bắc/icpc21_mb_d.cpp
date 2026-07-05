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

#define el cout << '\n'
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 1'000'007

bool used[mxn];

inline void LonggVuz(){
	string s; cin >> s;
	int n = len(s);
	fo(i, 1, n) used[i] = 0;
	s = " " + s + " ";
	int res = 0;
	fo(i, 1, n) if(s[i] == '1'){
		if(i > 1 and s[i - 1] == '0' and !used[i - 1]){
			used[i - 1] = 1;
			continue;
		}
		if(i < n and s[i + 1] == '0' and !used[i + 1]){
			used[i + 1] = 1;
			continue;
		}
		++res;
	}
	cout << res, el;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(1) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
