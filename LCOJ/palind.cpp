// https://luyencode.net/problem/palind
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
const int mxn = 5e3 + 7;

string a;
int n, q, f[mxn][mxn];
bool dx[mxn][mxn];

void LonggVuz(){
	cin >> a;
	n = len(a);
	a = "@" + a;
	for(int i=1; i<=n; i++){
		dx[i][i] = f[i][i] = 1;
	}
	for(int len=2; len<=n; len++){
		for(int i=1; i<=n-len+1; i++){
			int j = i + len - 1;
			if(a[i] == a[j]){
				if(len == 2){
					dx[i][j] = 1;
				}else dx[i][j] = dx[i+1][j-1];
			}
			f[i][j] = f[i+1][j] + f[i][j-1] - f[i+1][j-1];
			if(dx[i][j]) ++f[i][j];
		}
	}
	cin >> q;
	while(q--){
		int l, r; cin >> l >> r;
		cout << f[l][r] << el;
	}
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
