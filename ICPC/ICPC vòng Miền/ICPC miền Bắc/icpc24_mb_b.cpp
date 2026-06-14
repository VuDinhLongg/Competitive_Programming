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
#define mxn 10'007

struct node{
    int w, i, m;
};

int n, dp[mxn];
node a[mxn];

inline void LonggVuz(){
    cin >> n;
    fo(i, 1, n){
        cin >> a[i].w >> a[i].i >> a[i].m;
    }
    sort(a+1, a+n+1, [&](node &x, node &y){
        return x.w < y.w;
    });
    int res = 0;
    fo(i, 1, n){
        dp[i] = a[i].m;
        fo(j, 1, i - 1){
            if(a[i].i >= a[j].i){
                dp[i] = max(dp[i], dp[j] + a[i].m);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}