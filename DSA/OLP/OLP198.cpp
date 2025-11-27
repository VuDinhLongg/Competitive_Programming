/*----------------------
   Author : @LonggVuz
----------------------*/
#include <bits/stdc++.h>
using namespace std;

#ifdef ChatGPT
#include <ChatGPT.h>
#else
#define debug(...) 1608
#define print(...) 2005
#endif

#define el cout << '\n'
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define out(x) return void(cout << (x))
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
// #define int int64_t

const int mod = 1e9 + 7;
// const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

int n, dp[505][505][505], cur, nxt;
char a[505][505];
int di[] = {1, 1, 0, 0};
int dj[] = {0, 0, 1, 1};
int dx[] = {-1, 0, -1, 0};
int dy[] = {0, -1, 0, -1};

bool check(int td){
    return 1 <= td and td <= n;
}

int cal(int i, int x, int t){
    int j = 1 + t - (i - 1);
    int y = n - (t - (n - x));
    if(a[i][j] != a[x][y]) return 0;
    int &res = dp[i][x][t];
    if(res != -1) return res;
    res = 0;
    fo(k, 0, 3){
        int ii = i + dx[k];
        int jj = j + dy[k];
        int xx = x + di[k];
        int yy = y + dj[k];
        if(check(ii) and check(jj) and check(xx) and check(yy)){
            res += cal(ii, xx, t - 1);
            res %= mod;
        }
    }
    return res;
}

inline void LonggVuz(){
    cin >> n;
    fo(i, 1, n) fo(j, 1, n){
        cin >> a[i][j];
    }
    memset(dp, -1, sizeof dp);
    dp[1][n][0] = 1;
    fo(k, 1, n - 1) fo(i, 1, k + 1) fd(j, n, n - k){
        cal(i, j, k);
    }
    int res = 0;
    fo(i, 1, n){
        res += cal(i, i, n - 1);
        res %= mod;
    }
    cout << res;
}

signed main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    
    signed o_o = 1; if(false) cin >> o_o;
    fo(_, 1, o_o) print(_), LonggVuz();
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
