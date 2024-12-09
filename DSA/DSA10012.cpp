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
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define set(a, x) memset(a, x, sizeof(a))
#define bit(a, x) (a >> x & 1)
#define pb push_back
#define is insert
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

int n, m, d[105][105];

void LonggVuz(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i != j) d[i][j] = oo;
		}
	}
	while(m--){
		int x, y; cin >> x >> y;
		d[x][y] = 1;
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i != j){
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}
	ld res = 0, cnt = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i != j and d[i][j] != oo){
				res += d[i][j];
				++cnt;
			}
		}
	}
	cout << fix(2) << res / cnt << el;
}

signed main(){
	Sonic();
	
	signed test = 1;
	cin >> test;
	for(signed i=1; i<=test; i++){
		LonggVuz();
	}
	
	End();
}