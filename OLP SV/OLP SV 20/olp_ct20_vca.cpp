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
#define len(x) (x).size()
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 200'007

int k;
string s;
int cnt[mxn][3], dp[mxn];

bool check(int l, int r){
	rep(i, 3){
		int x = cnt[r][i] - cnt[l - 1][i];
		if(x < k) return 1;
	}
	return 0;
}

inline void LonggVuz(){
    cin >> k >> s;
    int n = len(s);
    s = " " + s;
    fo(i, 1, n) if(s[i] == 'V') s[i] = 'B';
    fo(i, 1, n){
    	rep(j, 3) cnt[i][j] = cnt[i - 1][j];
    	++cnt[i][s[i] - 'A'];
    }
    int res = 1e18;
    fo(i, 1, n){
    	int l = 0, r = i + 1;
    	while(r - l > 1){
    		int mid = l + r >> 1;
    		if(check(mid, i)) r = mid;
    		else l = mid;
    	}
    	if(l == 0) continue;
    	int ans = 0;
    	rep(j, 3) ans += (cnt[i][j] - cnt[l - 1][j]) - k;
    	mini(res, ans);
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
