// https://luyencode.net/problem/tsp
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
#define gel(x) getline(cin >> ws, x)
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

int n, m, c[22][22], f[1 << 20][20];

int cnt(int n){
	int s = 0;
	while(n){
		s += n % 2;
		n /= 2;
	}return s;
}

void LonggVuz(){
	cin >> n >> m;
	while(m--){
		int x, y, w; cin >> x >> y >> w;
		c[x - 1][y - 1] = w;
	}

	int en = 1 << n;
	for(int mask=1; mask<en; mask++){
		if(bit(mask, 0)){
			int dem = cnt(mask);
			if(dem == 2){
				for(int i=1; i<n; i++){
					if(bit(mask, i) and c[0][i]){
						f[mask][i] = c[0][i];
						break;
					}
				}
			}else if(dem > 2){
				for(int i=1; i<n; i++){
					if(bit(mask, i)){
						f[mask][i] = oo;
						int pre_mask = mask - (1 << i);
						for(int j=1; j<n; j++){
							if(bit(pre_mask, j) and f[pre_mask][j] and c[j][i]){
								f[mask][i] = min(f[mask][i], f[pre_mask][j] + c[j][i]);
							}
						}
					}
				}
			}
		}
	}
	int res = oo;
	for(int i=1; i<n; i++){
		if(c[i][0]) res = min(res, f[en - 1][i] + c[i][0]);
	}cout << res;
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
