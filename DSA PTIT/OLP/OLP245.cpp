// LonggVuz
#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<LonggVuz.h>
#else
#define debug(...)
#endif

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
#define float double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

int n, dp[505][505];
string a;

void LonggVuz(){
    cin >> n >> a;
    a.insert(begin(a), ' ');
    fo(i, 1, n) fo(j, 1, n) dp[i][j] = oo;
    fo(i, 1, n) dp[i][i] = 1;
    fo(len, 2, n){
        fo(i, 1, n - len + 1){
            int j = i + len - 1;
            fo(k, i, j - 1){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] - (a[i] == a[j]));
            }
        }
    }
    cout << dp[1][n];
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
