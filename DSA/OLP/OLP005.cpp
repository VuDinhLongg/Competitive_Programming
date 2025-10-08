// LonggVuz
#include<bits/stdc++.h>
using namespace std;
#define el cout << '\n'
#define inc(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define dec(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int32_t i=a; i<=b; i++)
#define fd(i, a, b) for(int32_t i=a; i>=b; i--)
#define out(x) return void(cout << (x));
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pb push_back
#define po pop_back
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 8;
const int mxn = 1e6 + 9;

#define bit(n, i) (n >> (i) & 1)
int n, a[101];

void sub123(){
    int sum = 0;
    fo(i, 1, n) sum += a[i];
    int mx = 1 << n;
    vec<int> dp(mx);
    int res = oo;
    fo(mask, 1, mx - 1){
        int sumAC = 0;
        fo(i, 1, n) if(bit(mask, i - 1)){
            sumAC += a[i];
        }
        fo(i, 1, n) if(bit(mask, i - 1)){
            int pre_mask = mask ^ (1 << (i - 1));
            if(dp[pre_mask] + a[i] <= sum / 3){
                dp[mask] = max(dp[mask], dp[pre_mask] + a[i]);
            }
        }
        int sumC = dp[mask];
        int sumA = sumAC - sumC;
        int sumB = sum - sumAC;
        if(sumA >= sumB and sumB >= sumC){
            res = min(res, sumA - sumC);
        }
    }
    cout << res;
}

void sub4(){
    int sum = 0;
    fo(i, 1, n) sum += a[i];
    vec<vec<int>> dp(1001, vec<int>(1001));
    dp[0][0] = 1;
    fo(i, 1, n){
        fd(j, 1e3, 0) fd(k, 1e3, 0){
            if(j >= a[i] and dp[j - a[i]][k]) dp[j][k] = 1;
            if(k >= a[i] and dp[j][k - a[i]]) dp[j][k] = 1;
        }
    }
    int res = oo;
    fo(i, 0, 1e3) fo(j, 0, i) if(dp[i][j]){
        int k = sum - i - j;
        if(i >= k and k >= j)
            res = min(res, (int)i - j);
    }
    cout << res;
}

void LonggVuz(){
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    if(n <= 20) sub123();
    else sub4();
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; //cin >> orz;
    while(orz--){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
