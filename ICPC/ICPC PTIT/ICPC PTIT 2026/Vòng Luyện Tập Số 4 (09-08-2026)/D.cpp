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
#define mask(n) (1ll << (n))
#define bit(n, i) ((n) >> (i) & 1)
#define one(n) __builtin_popcountll(n)
#define clz(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctzll(n)

int n, m, k[20], p[20], a[20], s[20][20], dp[mask(20)][20], f[mask(20)];

inline void LonggVuz(){
	cin >> n >> m;
	fo(i, 0, m - 1) cin >> k[i] >> p[i] >> a[i];
	fo(i, 0, n - 1) fo(j, 0, n - 1) cin >> s[i][j];
	fo(i, 0, n - 1){
		dp[mask(i)][i] = s[i][0];
		fo(j, 0, m - 1) if(k[j] == 1 and dp[mask(i)][i] >= p[j]){
			dp[mask(i)][i] += a[j];
		}
		maxi(f[mask(i)], dp[mask(i)][i]);
	}
	int full = mask(n) - 1;
	fo(mask, 1, full) if(one(mask) > 1){
		int t = one(mask) - 1;
		fo(i, 0, n - 1) if(bit(mask, i)){
			int pre_mask = mask ^ mask(i);
			maxi(dp[mask][i], f[pre_mask] + s[i][t]);
			maxi(f[mask], dp[mask][i]);
		}
		fo(j, 0, m - 1) if(k[j] == t + 1 and f[mask] >= p[j]){
			f[mask] += a[j];
		}
	}
	cout << f[full];
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}