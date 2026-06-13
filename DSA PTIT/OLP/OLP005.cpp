// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LonggVuz
#include <LonggVuz.h>
#else
#define debug(...)
#endif

#define el cout << '\n'
#define inc(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define dec(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
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
const int mxn = 1e6 + 7;

#define bit(n, i) ((n) >> (i) & 1)
int n, a[101];

void sub123(){
    int sum = 0;
    fo(i, 0, n - 1) sum += a[i];
    int lim = 1 << n;
    vec<int> dp(lim);
    int res = oo;
    fo(mask, 1, lim - 1){
        int sumAC = 0;
        fo(i, 0, n - 1) if(bit(mask, i)){
            sumAC += a[i];
        }
        fo(i, 0, n - 1) if(bit(mask, i)){
            int pre = mask ^ (1 << i);
            if(dp[pre] + a[i] <= sum / 3){
                dp[mask] = max(dp[mask], dp[pre] + a[i]);
            }
        }
        int sumC = dp[mask];
        int sumA = sumAC - sumC;
        int sumB = sum - sumAC;
        debug(mask, sumA, sumB, sumC);
        if(sumA >= sumB and sumB >= sumC){
            res = min(res, sumA - sumC);
        }
    }
    cout << res;
}

void sub4(){
    int sum = 0;
    fo(i, 0, n - 1) sum += a[i];
    vec<vec<int>> dp(1001, vec<int>(1001));
    dp[0][0] = 1;
    fo(i, 0, n - 1){
        fd(j, 1e3, 0) fd(k, 1e3, 0){
            if(j >= a[i] and dp[j - a[i]][k]) dp[j][k] = 1;
            if(k >= a[i] and dp[j][k - a[i]]) dp[j][k] = 1;
        }
    }
    int res = oo;
    fo(i, 0, 1e3) fo(j, 0, 1e3) if(dp[i][j]){
        debug(i, j);
        int sumA = i;
        int sumC = j;
        int sumB = sum - sumA - sumC;
        if(sumA >= sumB and sumB >= sumC){
            res = min(res, sumA - sumC);
        }
    }
    cout << res;
}

inline void LonggVuz(){
    cin >> n;
    fo(i, 0, n - 1) cin >> a[i];
    if(n <= 20) sub123();
    else sub4();
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
