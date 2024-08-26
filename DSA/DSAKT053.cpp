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
#define ms(a, x) memset(a, x, sizeof(a))
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

int f[1005][1005];
void solve(str a, int n, str b, int m){
	a = "@" + a; b = "@" + b;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i] == b[j]){
				f[i][j] = f[i-1][j-1] + 1;
			}else{
				f[i][j] = max(f[i-1][j], f[i][j-1]);
			}
		}
	}cout << f[n][m] << el;
}

signed main(){
	LonggVuz();
	
	tc(){
		str a, b; cin >> a >> b;
		solve(a, len(a), b, len(b));
	}
	
	End();
}