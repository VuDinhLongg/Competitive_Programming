// Accepted on Subtask 1 + 2 (60%)
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
#define mxn 100'007

int p, q, n;
string s;

namespace sub1{
	bool check(){
		return n <= 100 and q <= 100;
	}
	void solve(){
		while(q--){
			int l, r; cin >> l >> r;
			int res = 0;
			fo(i, l, r){
				int rem = 0;
				fo(j, i, r){
					rem = (rem * 10 + s[j] - '0') % p;
					if(rem == 0) ++res;
				}
			}
			cout << res, el;
		}
	}
}

namespace sub2{
	bool check(){
		return p == 2;
	}
	int cnt[mxn], dp[mxn];
	void solve(){
		fo(i, 1, n){
			cnt[i] = cnt[i - 1];
			dp[i] = dp[i - 1];
			if((s[i] - '0') % 2 == 0){
				++cnt[i];
				dp[i] += i;
			}
		}
		while(q--){
			int l, r; cin >> l >> r;
			int num = cnt[r] - cnt[l - 1];
			int res = (dp[r] - dp[l - 1]) - num * (l - 1);
			cout << res, el;
		}
	}
}

namespace sub3{
	bool check(){
		
	}
	void solve(){
		
	}
}

inline void LonggVuz(){
	cin >> p >> s >> q;
	n = len(s);
	s = " " + s;
	if(sub1::check()) sub1::solve();
	else if(sub2::check()) sub2::solve();
	else sub3::solve();
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(false) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
