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
const int mxm = 1 << 16;

#define bit(n, i) ((n) >> (i) & 1)
int n, c[16][16], dp[mxm];

void LonggVuz(){
    cin >> n;
    fo(i, 0, n - 2){
        fo(j, i + 1, n - 1){
            cin >> c[i][j];
            c[j][i] = c[i][j];
        }
    }
    int lim = 1 << n;
    fo(mask, 1, lim - 1) if(__builtin_popcount(mask) >= 2){
        fo(i, 0, n - 1) if(bit(mask, i)){
            fo(j, 0, n - 1) if(j != i and bit(mask, j)){
                int pre = mask ^ (1 << i) ^ (1 << j);
                dp[mask] = max(dp[mask], dp[pre] + c[i][j]);
            }
        }
    }
    cout << dp[lim - 1];
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
