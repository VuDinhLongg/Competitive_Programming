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

int n, m, a[1005][1005], dp[4][1005][1005];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

inline void LonggVuz(){
    cin >> n >> m;
    fo(i, 1, n) fo(j, 1, m){
    	cin >> a[i][j];
    }
    fo(i, 1, n){
    	fo(j, 1, m){
    		fo(k, 0, 1) dp[k][i][j] = max(dp[k][i + dx[k]][j + dy[k]], a[i][j]);
    	}
    }
    fd(i, n, 1){
    	fd(j, m, 1){
    		fo(k, 2, 3) dp[k][i][j] = max(dp[k][i + dx[k]][j + dy[k]], a[i][j]);
    	}
    }
    int res = 0;
    fo(i, 1, n) fo(j, 1, m){
    	bool ok = 0;
    	rep(k, 4) if(a[i][j] > dp[k][i + dx[k]][j + dy[k]]){
    		ok = 1; break;
    	}
    	dbg(i, j, ok);
    	res += ok;
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
