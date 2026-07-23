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

string s;
int n, q, z[mxn], cnt[mxn];

inline void LonggVuz(){
	cin >> s >> q;
	n = len(s);
	s = " " + s;
	int l = 0, r = 0;
	fo(i, 2, n){
		if(i <= r) z[i] = min(z[i - l + 1], r - i + 1);
		while(i + z[i] <= n and s[z[i] + 1] == s[i + z[i]]) ++z[i];
		if(maxi(r, i + z[i] - 1)) l = i;
		++cnt[1];
		--cnt[z[i] + 1];
	}
	fo(i, 1, n) cnt[i] += cnt[i - 1];
	while(q--){
		int l; cin >> l;
		if(z[n - l + 1] >= l and cnt[l] + 1 >= 3){
			cout << "YES " << cnt[l] + 1, el;
		}else cout << "NO", el;
	}
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
