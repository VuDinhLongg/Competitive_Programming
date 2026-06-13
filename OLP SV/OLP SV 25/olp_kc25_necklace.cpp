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

const int mxm = 1 << 26;

int n, a[mxn], dp[mxm];
string s[mxn];

inline void LonggVuz(){
    cin >> n;
    fo(i, 1, n){
    	cin >> s[i];
    	vector<int> cnt(26);
    	for(char &c : s[i]){
    		cnt[c - 'a'] ^= 1;
    	}
    	fo(j, 0, 25) if(cnt[j]){
    		a[i] ^= 1 << j;
    	}
    }
    int res = 0;
    fo(i, 1, n){
    	res += dp[a[i]];
    	fo(j, 0, 25){
    		int v = 1 << j;
    		res += dp[a[i] ^ v];
    	}
    	++dp[a[i]];
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}