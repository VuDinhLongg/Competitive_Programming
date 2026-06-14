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

int n, m, k, dp[mxn];
vector<vector<int>> a, pf;

inline void LonggVuz(){
    cin >> n >> m >> k;
    a.resize(n + 5, vector<int>(m + 5));
    pf.resize(n + 5, vector<int>(m + 5));
    fo(i, 1, n) fo(j, 1, m){
        cin >> a[i][j];
        pf[i][j] = pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1] + a[i][j];
    }
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    int res = 0;
    fd(i, n, 1){
        fo(j, 1, i){
            if(pf[i][m] - pf[j - 1][m] <= res) break;
            vector<int> val;
            fo(c, 1, m){
                int sum = (pf[i][c] - pf[j - 1][c] + k) % k;
                if(dp[sum] != -1){
                    res = max(res, pf[i][c] - pf[j - 1][c] - dp[sum]);
                    dp[sum] = min(dp[sum], pf[i][c] - pf[j - 1][c]);
                }else{
                    dp[sum] = pf[i][c] - pf[j - 1][c];
                }
                if(sum) val.push_back(sum);
            }
            for(int &j : val) dp[j] = -1;
        }
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}