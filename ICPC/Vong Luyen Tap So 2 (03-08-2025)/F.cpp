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

#define pe pair<int, int>
#define fi first
#define se second
int n, dp[101][10001];
pe a[mxn];

void LonggVuz(){
    cin >> n;
    int s = 0;
    fo(i, 1, n) cin >> a[i].fi, s += a[i].fi;
    fo(i, 1, n) cin >> a[i].se;
    fo(i, 1, n) fd(j, i - 1, 0) fd(cur, 1e4 - a[i].se, 0){
        if((j == 0 and cur == 0) or dp[j][cur]){
            dp[j + 1][cur + a[i].se] = max(dp[j + 1][cur + a[i].se], dp[j][cur] + a[i].fi);
        }
    }
    int res = oo;
    fo(i, 1, n){
        bool stop = 0;
        fo(j, s, 1e4) if(dp[i][j] > 0){
            // cout << dp[i][j] << ' ';
            res = min(res, s - dp[i][j]);
            stop = 1;
        }
        if(stop){
            cout << i << ' ';
            break;
        }
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
