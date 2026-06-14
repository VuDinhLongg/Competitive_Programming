/*======================
   Author : @LonggVuz
======================*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define orz(...) 2005
#endif

#define el cout << '\n'
#define all(x) begin(x), end(x)
#define fix(x) fixed << setprecision(x)
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 1'000'007
#define pii pair<int, int>
#define pip pair<int, pii>
#define ppi pair<pii, int>
#define ppp pair<pii, pii>
#define fi first
#define se second

int n, m, xst, yst, xen, yen, dp[5][101][101];
char a[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

inline void LonggVuz(){
    cin >> n >> m;
    fo(i, 1, n) fo(j, 1, m){
        cin >> a[i][j];
        if(a[i][j] == 'S'){
            xst = i; yst = j;
        }else if(a[i][j] == 'D'){
            xen = i; yen = j;
        }
        fo(k, 0, 3) dp[k][i][j] = 1e18;
    }
    dp[3][xst][yst] = 0;
    queue<ppp> q;
    q.push({{dp[3][xst][yst], 3}, {xst, yst}});
    while(!q.empty()){
        auto [cur, td] = q.front(); q.pop();
        auto [val, hp] = cur;
        auto [i, j] = td;
        if(i == xen and j == yen) break;
        fo(k, 0, 3){
            int ii = i + dx[k];
            int jj = j + dy[k];
            if(1 <= ii and ii <= n and 1 <= jj and jj <= m){
                int c = (a[ii][jj] == '+' ? -1 : 0);
                if(hp + c > 0 and dp[hp][i][j] + 1 < dp[hp + c][ii][jj]){
                    dp[hp + c][ii][jj] = dp[hp][i][j] + 1;
                    q.push({{dp[hp + c][ii][jj], hp + c}, {ii, jj}});
                }
            }
        }
    }
    int res = 1e18;
    fo(i, 1, 3) res = min(res, dp[i][xen][yen]);
    if(res < 1e18) cout << res;
    else cout << -1;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}