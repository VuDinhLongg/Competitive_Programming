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
#define pub push_back
#define pob pop_back
#define int int64_t
#define long int64_t

const int mod = 1e9 + 7;
const int mxn = 5e3 + 7;
const int mxm = 2e6 + 7;

int n, q, a[mxn], mx = 1e6, cnt[mxm];
long dp[mxn][mxn];

void LonggVuz(){
    cin >> n >> q;
    fo(i, 1, n){
        cin >> a[i];
        a[i] += mx;
    }
    fo(len, 2, n){
        fo(i, 2, len - 1) ++cnt[a[i]];
        fo(i, 1, n - len + 1){
            int j = i + len - 1;
            int aim = mx * 3 - a[i] - a[j];
            dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            if(0 <= aim and aim <= 2e6) dp[i][j] += cnt[aim];
            --cnt[a[i + 1]];
            ++cnt[a[j]];
        }
        fo(i, n - len + 3, n) --cnt[a[i]];
    }
    while(q--){
        int l, r; cin >> l >> r;
        cout << dp[l][r], el;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; //cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
