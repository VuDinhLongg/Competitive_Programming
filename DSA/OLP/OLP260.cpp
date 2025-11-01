// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LonggVuz
#include <LonggVuz.h>
#else
#define debug(...)
#endif

template<class X, class Y> bool maxi(X &a, const Y &b){ return b > a ? a = b, 1 : 0; }
template<class X, class Y> bool mini(X &a, const Y &b){ return b < a ? a = b, 1 : 0; }

#define el cout << '\n'
#define fup(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define fdn(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int32_t i=a; i<=b; i++)
#define fd(i, a, b) for(int32_t i=a; i>=b; i--)
#define out(x) return void(cout << (x))
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define dub double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e5 + 7;

int n, q, a[mxn], pf[mxn], dp[50][mxn], sum[50][mxn], pos[50][mxn];

inline void LonggVuz(){
    cin >> n;
    fo(i, 0, n - 1) cin >> a[i];
    pf[0] = a[0];
    fo(i, 1, n - 1) pf[i] = pf[i - 1] + a[i];
    fo(i, 0, n - 1){
        dp[0][i] = sum[0][i] = a[i];
        pos[0][i] = 1;
    }
    fo(k, 1, 48){
        fo(i, 0, n - 1){
            int d = 1ll << (k - 1);
            int j = (i + d) % n;
            sum[k][i] = sum[k - 1][i] + sum[k - 1][j];
            if(dp[k - 1][i] > sum[k - 1][i] + dp[k - 1][j]){
                dp[k][i] = dp[k - 1][i];
                pos[k][i] = pos[k - 1][i];
            }else{
                dp[k][i] = sum[k - 1][i] + dp[k - 1][j];
                pos[k][i] = d + pos[k - 1][j];
            }
        }
    }
    cin >> q;
    int i = 0;
    while(q--){
        int b; cin >> b;
        int res = 0, cur = 0;
        fd(k, 48, 0) if(cur + dp[k][i] < b){
            cur += dp[k][i];
            res += pos[k][i];
            i += pos[k][i];
            i %= n;
            ++k;
        }
        ++res;
        i = (i + 1) % n;
        cout << res, el;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; if(false) cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
