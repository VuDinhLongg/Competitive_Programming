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
#define mxn 300'007
#define mask(n) (1ll << (n))
#define bit(n, i) ((n) >> (i) & 1)
#define one(n) __builtin_popcountll(n)
#define clz(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctzll(n)

int n, a[mxn], s[mxn], cnt[2][mxn];

inline void LonggVuz(){
	cin >> n;
	fo(i, 1, n) cin >> a[i];
	fo(i, 1, n){
		a[i] = one(a[i]);
		s[i] = s[i - 1] + a[i];
	}
	int res = 0;
	++cnt[0][0];
	fo(i, 1, n){
		int mx = 0;
		fd(j, i, i - 67) if(j > 0){
			maxi(mx, a[j]);
			int sum = s[i] - s[j - 1];
			if(sum % 2 == 0 and mx <= sum - mx) ++res;
		}
		if(i >= 69){
			res += cnt[s[i] & 1][i - 69];
		}
		cnt[0][i] = cnt[0][i - 1];
		cnt[1][i] = cnt[1][i - 1];
		++cnt[s[i] & 1][i];
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}