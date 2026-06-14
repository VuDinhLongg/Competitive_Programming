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

int n, d, h, a[10005], dp[10005];

inline void LonggVuz(){
    cin >> n >> d >> h;
    fo(i, 1, n) cin >> a[i];
    dp[1] = a[1];
    fo(i, 2, n) dp[i] = 1e18;
    fo(i, 1, n){
        fo(j, i + 1, min(n, i + d)){
            if(abs(a[i] - a[j]) <= h) dp[j] = min(dp[j], dp[i] + a[j]);
        }
    }
    cout << dp[n];
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}