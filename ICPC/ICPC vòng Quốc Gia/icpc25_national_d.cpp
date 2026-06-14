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
#define mxn 200'007

const int mod = 998244353;

int n, a[mxn], dp[mxn], cnt[mxn];

inline void LonggVuz(){
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    fo(i, 1, n) dp[i] = cnt[i] = 0;
    dp[0] = dp[1] = 1;
    fo(i, 2, n){
        dp[i] = dp[i - 1];
        cnt[i] = cnt[i - 1];
        if(a[i] - a[i - 1] <= 1){
            if(maxi(cnt[i], cnt[i - 2] + 1)){
                dp[i] = dp[i - 2];
            }else if(cnt[i] == cnt[i - 2] + 1){
                dp[i] += dp[i - 2];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[n], el;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(1) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}