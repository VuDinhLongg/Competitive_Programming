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

int k, n, x, y, mod;
int a[501][101][101], dp[501][101][101];

int Mul(int a, int b){
	if(b < 0) return Mul(-a, -b);
	if(b == 0) return 0;
	int res = Mul(a, b / 2);
	res = res + res;
	if(b & 1) res += a;
	return res % mod;
}

int calc(int idx, int x, int y){
	if(idx == 1) return a[1][x][y];
	int &res = dp[idx][x][y];
	if(res != -1) return res;
	res = 0;
	fo(i, 1, n) res = (res + Mul(calc(idx - 1, x, i), a[idx][i][y])) % mod;
	return res;
}

inline void LonggVuz(){
    cin >> k >> n >> x >> y >> mod;
    fo(idx, 1, k){
    	fo(i, 1, n) fo(j, 1, n){
    		cin >> a[idx][i][j];
    	}
    }
    memset(dp, -1, sizeof dp);
    int res = calc(k, x, y);
    if(res < 0) res += mod;
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
