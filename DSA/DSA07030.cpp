// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Noob C++
void End(){
    cerr << "=> Thời gian code chạy: ";
    cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define LonggVuz() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define ms(x) memset(x, 0, sizeof(x))
#define tc() int TC; cin >> TC; while(TC--)
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define str string
#define int intmax_t
#define ld long double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int n, m, a[505][505], f[505][505];

void solve(){
	int res = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(f[i][j]){
				int x = f[i][j];
				res = max(res, x);
				for(int k=j+1; k<=m; k++){
					if(f[i][k] == 0) break;
					x = min(x, f[i][k]);
					res = max(res, x * (k - j + 1));
				}
			}
		}
	}cout << res << el;
}

signed main(){
	LonggVuz();
	
	tc(){
		cin >> n >> m;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				cin >> a[i][j];
				if(a[i][j]){
					f[i][j] = f[i-1][j] + 1;
				}else f[i][j] = 0;
			}
		}solve();
	}
	
	End();
}