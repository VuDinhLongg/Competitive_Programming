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
#define int int32_t

const int mod = 1e9 + 7;
const int oo = 1e8 + 7;
const int mxn = 1e5 + 7;

string a;
int n, dp[mxn], pos[1 << 26];

void LonggVuz(){
    cin >> a;
    n = len(a);
    fo(i, 1, n) dp[i] = oo;
    a.insert(begin(a), ' ');
    int cur = 0;
    fo(i, 1, n){
        int c = a[i] - 'a';
        cur ^= 1 << c;
        dp[i] = dp[i - 1] + 1;
        if(cur == 0 or pos[cur] > 0){
            dp[i] = min(dp[i], dp[pos[cur]] + 1);
        } 
        for(int mask = 1; mask < (1 << 26); mask <<= 1){
            int pre = cur ^ mask;
            if(pre == 0 or pos[pre] > 0){
                dp[i] = min(dp[i], dp[pos[pre]] + 1);
            }
        }
        if(cur > 0 and pos[cur] == 0) pos[cur] = i;
        else if(dp[i] < dp[pos[cur]]) pos[cur] = i;
    }
    // fo(i, 1, n) cout << dp[i], el;
    cout << dp[n];
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
