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

int dp[2][150][150][3];

bool nto(int n){
    if(n == 2 or n == 3) return 1;
    if(n < 2 or n % 2 == 0 or n % 3 == 0) return 0;
    int c = sqrtl(n);
    for(int i=5; i<=c; i+=6){
        if(n % i == 0 or n % (i + 2) == 0) return 0;
    }
    return 1;
}

void LonggVuz(){
    int n; cin >> n;
    vec<int> a;
    while(n){
        a.pub(n % 10);
        n /= 10;
    }
    dp[0][0][0][0] = 1;
    int cur = 0;
    fo(i, 0, len(a) - 1){
        int nxt = cur ^ 1;
        memset(dp[nxt], 0, sizeof dp[nxt]);
        fo(sumx, 0, i * 9) fo(sumy, 0, i * 9) fo(car, 0, 2) if(dp[cur][sumx][sumy][car]){
            // cout << cur << ' ' << sumx << ' ' << sumy << ' ' << car, el;
            int d = a[i];
            fo(x, 0, 9) fo(y, 0, 9){
                int nd = x + y * 2 + car;
                if(nd % 10 == d){
                    int ncar = nd / 10;
                    dp[nxt][sumx + x][sumy + y][ncar] += dp[cur][sumx][sumy][car];
                }
            }
        }
        cur = nxt;
    }
    int res = 0;
    fo(i, 2, 140) fo(j, 2, 140) if(dp[cur][i][j][0] > 0 and nto(i) and nto(j)){
        // cout << i << ' ' << j << ' ' << dp[cur][i][j][0], el;
        res += dp[cur][i][j][0];
    }
    cout << res;
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
