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

int n, s, h, w[101], c[101], dp[100001][2];

inline void LonggVuz(){
    cin >> n >> s >> h;
    fo(i, 1, n) cin >> w[i] >> c[i];
    fo(i, 1, 1e5) dp[i][0] = dp[i][1] = 1e18;
    fo(i, 1, n){
        fd(j, 1e5, c[i]){
            if(dp[j - c[i]][0] + w[i] < dp[j][0]){
                dp[j][0] = dp[j - c[i]][0] + w[i];
            }
            if(dp[j - c[i]][1] + w[i] < dp[j][1]){
                dp[j][1] = dp[j - c[i]][1] + w[i];
            }
            if(h >= w[i] and dp[j - c[i]][0] < dp[j][1]){
                dp[j][1] = dp[j - c[i]][0];
            }
        }
    }
    fd(i, 1e5, 1) if(min(dp[i][0], dp[i][1]) <= s){
        cout << i; break;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}