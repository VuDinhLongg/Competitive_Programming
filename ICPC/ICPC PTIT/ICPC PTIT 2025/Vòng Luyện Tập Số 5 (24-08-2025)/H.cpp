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

int n, m, r, c, a[1001][1001], dp[1001][1001];

bool check(int aim){
    fo(i, 1, n) fo(j, 1, m){
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        if(a[i][j] <= aim) ++dp[i][j];
        else --dp[i][j];
        if(i >= r and j >= c){
            int res = dp[i][j] - dp[i - r][j] - dp[i][j - c] + dp[i - r][j - c];
            if(res > 0) return 1;
        }
    }
    return 0;
}

void LonggVuz(){
    cin >> n >> m >> r >> c;
    fo(i, 1, n) fo(j, 1, m){
        cin >> a[i][j];
    }
    int l = -1, r = 1e9;
    while(r - l > 1){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
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
