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
#define fix(x) fixed << setprecision(x)
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 1'000'007

int n, q, cnt[mxn][26], dp[26];
string s;

inline void LonggVuz(){
    cin >> n >> q >> s;
    fo(i, 1, n){
    	rep(j, 26) cnt[i][j] = cnt[i - 1][j];
    	++cnt[i][s[i - 1] - 'a'];
    }
    while(q--){
    	int l, r; cin >> l >> r;
    	++l; ++r;
    	rep(i, 26) dp[i] = cnt[r][i] - cnt[l - 1][i];
    	int res = 0;
    	rep(i, 26) res += dp[i] & 1;
    	dbg(res);
    	cout << res / 2, el;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
