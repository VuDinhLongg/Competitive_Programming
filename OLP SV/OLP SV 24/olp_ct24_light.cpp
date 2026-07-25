/*======================
   Author : @LonggVuz (TLE 16/20)
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

int n, k, s[mxn], b[mxn];
bitset<505> dp[3];

int sum(int l, int r){
	return (l + r) * (r - l + 1) / 2;
}

int row(int u){
	int l = 0, r = n + 1;
	while(r - l > 1){
		int mid = l + r >> 1;
		if(u <= sum(1, mid)) r = mid;
		else l = mid;
	}
	return r;
}

inline void LonggVuz(){
	cin >> n >> k;
	int m = n * (n + 1) / 2;
	fo(i, 1, m) b[i] = 1;
	fo(i, 1, k){
		cin >> s[i];
		b[s[i]] = 0;
	}
	int res = 0;
	fo(i, 1, m){
		int r = row(i);
		fo(j, 1, n - r){
			{
				int u = i;
				dbg(i, j, u);
				dp[0].reset();
				fo(idx, 0, j - 1){
					dp[0][idx] = b[u];
					u += r + idx;
				}
			}
			{
				int u = i + sum(r, r + j - 1);
				dbg(i, j, u);
				dp[1].reset();
				fo(idx, 0, j - 1){
					dp[1][idx] = b[u];
					u += 1;
				}
			}
			{
				int u = i + sum(r, r + j - 1) + j;
				dbg(i, j, u);
				dp[2].reset();
				fo(idx, 0, j - 1){
					dp[2][idx] = b[u];
					u -= r + j - idx;
				}
			}
			dbg(i, j, dp[0], dp[1], dp[2]);
			dp[0] = dp[0] & dp[1] & dp[2];
			res += dp[0].count();
		}
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
