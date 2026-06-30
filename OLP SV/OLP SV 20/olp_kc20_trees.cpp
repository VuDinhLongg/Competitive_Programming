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

int n, k, m, a[mxn];

namespace sub1{
	bool check(){
		return n <= 100 and m <= 50;
	}
	int dp[505], bad[505];
	void solve(){
		fo(i, 1, m) bad[a[i]] = 1;
		fo(i, n + 1, n + k) bad[i] = 1;
		fo(i, 1, n + k - 1){
			dp[i] = 1e18;
			int add = 0, idx = max(i - k + 1, (int)1);
			fo(p, idx, i) if(!bad[p]) ++add;
			int lim = i - k;
			maxi(lim, 0);
			fo(j, 0, lim){
				bool ok = 1;
				fo(p, j + 1, i - k) if(bad[p]){
					ok = 0; break;
				}
				if(ok) mini(dp[i], dp[j] + add);
			}
		}
		int res = 1e18;
		fo(i, a[m], a[m] + k - 1) mini(res, dp[i]);
		cout << n - m - res;
	}
}

namespace sub2{
	bool check(){
		return n <= 2e5 and m <= 1e5;
	}
	int dp[mxn], bad[mxn];
	int calc(int l, int r){
		mini(r, n);
		int lo = lower_bound(a+1, a+m+1, l) - a;
		int hi = upper_bound(a+1, a+m+1, r) - a - 1;
		return (r - l + 1) - (hi - lo + 1);
	}
	void solve(){
		fo(i, 1, m) bad[a[i]] = 1;
		fo(i, n + 1, n + k) bad[i] = 1;
		int msl = 0, msr = 0;
		multiset<int> ms;
		int j = 0;
		fo(i, 1, n + k - 1){
			dp[i] = 1e9;
			while(j + 1 <= m and a[j + 1] < i - k + 1) ++j;
			// [a[j], i - k]
			int l = a[j], r = i - k; maxi(r, 0);
			while(msr <= r) ms.insert(dp[msr]), ++msr;
			while(msl < l) ms.erase(ms.find(dp[msl])), ++msl;
			int add = calc(max(i - k + 1, (int)1), i);
			mini(dp[i], *ms.begin() + add);
		}
		int res = 1e18;
		fo(i, a[m], a[m] + k - 1) mini(res, dp[i]);
		cout << n - m - res;
	}
}

namespace sub3{
	bool check(){
		return 1;
	}
	int dp[mxn], idx[mxn];
	void solve(){
		int mm = m;
		fo(i, 1, mm) if(a[i] + k - 1 > n){
			++m;
			a[m] = a[i] + k - 1;
			idx[m] = i;
		}
		int j = 0;
		fo(i, 1, m){
			while(j + 1 <= m and a[j + 1] < a[i] - k + 1) ++j;
			int l = max(a[i] - k + 1, (int)1);
			int r = a[i];
			int add = (r - l + 1) - (i - j);
			if(a[i] > n){
				int j = idx[i];
				add = (n - a[j] + 1) - (mm - j + 1);
			}
			dp[i] = dp[j] + add;
		}
		int res = 1e18;
		fo(i, mm, m) mini(res, dp[i]);
		cout << n - mm - res;
	}
}

inline void LonggVuz(){
	cin >> n >> k >> m;
	fo(i, 1, m) cin >> a[i];
	sort(a+1, a+m+1);
	if(sub1::check()) sub1::solve();
	else if(sub2::check()) sub2::solve();
	else sub3::solve();
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(false) cin >> o;
	rep(i, o) orz(i), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
