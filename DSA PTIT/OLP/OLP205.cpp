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

#define pe pair<int, int>
#define fi first
#define se second
int n, m, q, dp[1001][1001];
char a[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void LonggVuz(){
    cin >> n >> m >> q;
    fo(i, 1, n) fo(j, 1, m){
        cin >> a[i][j];
    }
    queue<pe> qe;
    fo(i, 1, n) fo(j, 1, m){
        if(a[i][j] == '*'){
            qe.push({i, j});
        }else dp[i][j] = oo;
    }
    while(!qe.empty()){
        auto [i, j] = qe.front(); qe.pop();
        fo(k, 0, 3){
            int ii = i + dx[k];
            int jj = j + dy[k];
            if(1 <= ii and ii <= n and 1 <= jj and jj <= m){
                int cost = a[i][j] != a[ii][jj];
                if(dp[i][j] + cost < dp[ii][jj]){
                    dp[ii][jj] = dp[i][j] + cost;
                    qe.push({ii, jj});
                }
            }
        }
    }
    while(q--){
        int x, y; cin >> x >> y;
        cout << dp[x][y], el;
    }
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
