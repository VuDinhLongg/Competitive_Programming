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

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 2e5 + 7;

int n, k, a[mxn], dp[mxn];

void LonggVuz(){
    cin >> n >> k;
    fo(i, 1, n) cin >> a[i];
    int res = 0, l = 0;
    map<int, int> cnt;
    ++cnt[(dp[l] - l + k) % k];
    fo(r, 1, n){
        dp[r] = dp[r - 1] + a[r];
        while(r - l >= k){
            int del = (dp[l] - l + k) % k;
            --cnt[del];
            ++l;
        }
        int aim = (dp[r] - r + k) % k;
        if(cnt.count(aim)){
            // cout << dp[r] << ' ' << r << ' ' << aim << ' ' << cnt[aim], el;
            res += cnt[aim];
        }
        ++cnt[aim];
    }
    cout << res;
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
