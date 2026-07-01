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



inline void LonggVuz(){
	string s, t; cin >> s >> t;
	if(len(s) != len(t)) out("NO");
	int n = len(s);
	multiset<char> odds, evens, oddt, event;
	rep(i, n){
		if(i & 1){
			odds.insert(s[i]);
			oddt.insert(t[i]);
		}else{
			evens.insert(s[i]);
			event.insert(t[i]);
		}
	}
	cout << (odds == oddt and evens == event ? "YES" : "NO"), el;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(1) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
