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

#define pe pair<int, int>
#define fi first
#define se second
int n, m, dp[1001][1001];
int x, y, z, t;
char a[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void LonggVuz(){
    cin >> n >> m >> x >> y >> z >> t;
    fo(i, 1, n) fo(j, 1, m){
        cin >> a[i][j];
        dp[i][j] = oo;
    }
    dp[x][y] = 0;
    queue<pe> q;
    q.push({x, y});
    while(!q.empty()){
        auto tmp = q.front(); q.pop();
        int i = tmp.fi, j = tmp.se;
        if(i == z and j == t) break;
        fo(k, 0, 3){
            int ii = i + dx[k];
            int jj = j + dy[k];
            if(1 <= ii and ii <= n and 1 <= jj and jj <= m and a[ii][jj] == '.'){
                if(dp[i][j] + 1 < dp[ii][jj]){
                    dp[ii][jj] = dp[i][j] + 1;
                    q.push({ii, jj});
                }
            }
        }
        fo(x, max(1ll, i - 2), min(n, i + 2)){
            fo(y, max(1ll, j - 2), min(m, j + 2)){
                if(a[x][y] == '.' and dp[i][j] + 2 < dp[x][y]){
                    dp[x][y] = dp[i][j] + 2;
                    q.push({x, y});
                }
            }
        }
    }
    cout << (dp[z][t] < oo ? dp[z][t] : -1);
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
