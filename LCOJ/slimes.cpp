// https://luyencode.net/problem/slimes
// LonggVuz
#include<bits/stdc++.h>
using namespace std;
// ☞ Think twice, code once ☜
void End(){
    cerr << "=> Smoothly Finished! Time taken: ";
    cerr << (0.001 * clock()) << "s" << string(25, '\t');
}
#define Sonic() cin.tie(0) -> sync_with_stdio(0)
#define out(x) return cout << x, void()
#define fix(x) fixed << setprecision(x)
#define all(x) begin(x), end(x)
#define len(x) (int)x.size()
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

int ps[404], dp[404][404];

void LonggVuz(){
	int n; cin >> n;
	int a[n+5];
	for(int i=1; i<=n; i++){
		cin >> a[i];
		ps[i] = ps[i - 1] + a[i];
	}
	for(int len=2; len<=n; len++){
		for(int i=1; i<=n-len+1; i++){
			int j = i + len - 1;
			dp[i][j] = oo;
			for(int k=i; k<j; k++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + ps[j] - ps[i - 1]);
			}
		}
	}cout << dp[1][n];
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
