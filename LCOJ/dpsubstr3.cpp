// https://luyencode.net/problem/dpsubstr3
// LonggVuz
#include<bits/stdc++.h>
using namespace std;
// Think twice, code once ^.^
void End(){
    cerr << "=> Smoothly Finished! Time taken: ";
    cerr << (0.001 * clock()) << "s" << string(25, '\t');
}
#define Sonic() cin.tie(NULL) -> sync_with_stdio(false);
#define fix(x) fixed << setprecision(x)
#define all(x) begin(x), end(x)
#define len(x) (int)x.size()
#define out(x) return cout << x << el, void()
#define ms(a, x) memset(a, x, sizeof(a))
#define bit(n, x) (n >> x & 1)
#define pb push_back
#define is insert
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

int dp[2005][2005];;

void LonggVuz(){
	string a, b; cin >> a >> b;
	int n = len(a), m = len(b);
	a = "@" + a; b = "@" + b;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i] == b[j]){
				dp[i][j] = dp[i-1][j] + dp[i][j-1] + 1;
			}else dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			dp[i][j] = (dp[i][j] + mod) % mod;
		}
	}cout << dp[n][m];
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
