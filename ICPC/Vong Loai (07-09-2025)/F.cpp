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
const int mxn = 1e6 + 7;

int dp[mxn];
bool check(int n){
    string a = to_string(n);
    int l = 0, r = len(a) - 1, d = 0;
    while(l < r){
        if(a[l] != a[r]) ++d;
        ++l; --r;
    }
    return d <= 1;
}

void LonggVuz(){
    int l, r; cin >> l >> r;
    cout << dp[r] - dp[l - 1];
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    fo(i, 1, 1e6) dp[i] = dp[i - 1] + check(i);
    signed orz = 1; cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
