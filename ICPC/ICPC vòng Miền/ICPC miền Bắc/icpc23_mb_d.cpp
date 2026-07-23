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
// #define int long long
#define mxn 1'000'007
#define mask(n) (1ll << (n))
#define bit(n, i) ((n) >> (i) & 1)
#define one(n) __builtin_popcountll(n)
#define clz(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctzll(n)

const int mod = 123456789;

int n, m, k, dp[2][1 << 16][257], ok[1 << 16];
vector<int> pre[1 << 16];

bool valid(int mask){
	fo(i, 0, m - 2) if(bit(mask, i) and bit(mask, i + 1)) return 0;
	return 1;
}

bool check(int x, int y){
	fo(i, 0, m - 1) if(bit(y, i)){
		if(i - 1 >= 0 and bit(x, i - 1)) return 0;
		if(bit(x, i)) return 0;
		if(i + 1 < m and bit(x, i + 1)) return 0;
	}
	return 1;
}

inline void LonggVuz(){
	cin >> n >> m >> k;
	if(n < m) swap(n, m);
	int full = mask(m) - 1;
	fo(mask, 0, full) ok[mask] = valid(mask);
	fo(mask, 0, full) if(ok[mask]) fo(pre_mask, 0, full) if(ok[pre_mask] and check(pre_mask, mask)){
		pre[mask].push_back(pre_mask);
	}
	int cur = 0;
	fo(mask, 0, full) if(ok[mask]) dp[cur][mask][one(mask)] = 1;
	fo(i, 2, n){
		int nxt = cur ^ 1;
		fo(mask, 0, full) if(ok[mask]){
			fo(j, 0, k) dp[nxt][mask][j] = 0;
			for(int &pre_mask : pre[mask]){
				fo(j, 0, k) if(dp[cur][pre_mask][j] > 0 and j + one(mask) <= k){
					dp[nxt][mask][j + one(mask)] = (0ll + dp[nxt][mask][j + one(mask)] + dp[cur][pre_mask][j]) % mod;
				}
			}
		}
		cur = nxt;
	}
	int res = 0;
	fo(mask, 0, full) if(ok[mask]){
		res = (0ll + res + dp[cur][mask][k]) % mod;
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
