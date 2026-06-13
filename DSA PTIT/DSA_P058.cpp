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
const int mxn = 1e3 + 7;

#define pe pair<int, int>
#define fi first
#define se second
int n, m, a[mxn][mxn], dp[mxn][mxn];

void LonggVuz(){
    cin >> n >> m;
    fo(i, 1, n) fo(j, 1, m){
        cin >> a[i][j];
        dp[i][j] = oo;
    }
    queue<pe> q;
    q.push({1, 1});
    dp[1][1] = 0;
    while(!q.empty()){
        auto [i, j] = q.front(); q.pop();
        if(i == n and j == m) break;
        if(i + 1 <= n){
            int c = abs(a[i][j] - a[i + 1][j]);
            if(i + c <= n and dp[i][j] + 1 < dp[i + c][j]){
                dp[i + c][j] = dp[i][j] + 1;
                q.push({i + c, j});
            }
        }
        if(j + 1 <= m){
            int c = abs(a[i][j] - a[i][j + 1]);
            if(j + c <= m and dp[i][j] + 1 < dp[i][j + c]){
                dp[i][j + c] = dp[i][j] + 1;
                q.push({i, j + c});
            }
        }
        if(i + 1 <= n and j + 1 <= m){
            int c = abs(a[i][j] - a[i + 1][j + 1]);
            if(i + c <= n and j + c <= m and dp[i][j] + 1 < dp[i + c][j + c]){
                dp[i + c][j + c] = dp[i][j] + 1;
                q.push({i + c, j + c});
            }
        }
    }
    cout << (dp[n][m] < oo ? dp[n][m] : -1);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
