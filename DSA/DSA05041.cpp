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

int f[105][105];
void solve(str a, int n){
	ms(f, 0);
	a = "@" + a;
	int res = 1;
	for(int i=1; i<=n; i++) f[i][i] = 1;
	for(int l=2; l<=n; l++){
		for(int i=1; i<=n-l+1; i++){
			int j = i + l - 1;
			f[i][j] = max(f[i+1][j], f[i][j-1]);
			if(a[i] == a[j]){
				if(l == 2) f[i][j] = 2;
				else f[i][j] = max(f[i][j], f[i+1][j-1] + 2);
			}
		}
	}cout << n - f[1][n] << el;
}

signed main(){
	LonggVuz();
	
	tc(){
		str a; cin >> a;
		solve(a, len(a));
	}
	
	End();
}