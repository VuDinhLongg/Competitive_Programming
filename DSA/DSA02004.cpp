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

int n;
bool a[10][10], vis[10][10], ok;

void run(int i, int j, str s){
	if(i == n && j == n){
		cout << s << ' '; 
		ok = 1; return;
	}vis[i][j] = 1;
	if(i + 1 <= n && a[i+1][j] && !vis[i+1][j]) run(i + 1, j, s + "D");
	if(j - 1 >= 1 && a[i][j-1] && !vis[i][j-1]) run(i, j - 1, s + "L");
	if(j + 1 <= n && a[i][j+1] && !vis[i][j+1]) run(i, j + 1, s + "R");
	if(i - 1 >= 1 && a[i-1][j] && !vis[i-1][j]) run(i - 1, j, s + "U");
	vis[i][j] = 0;
}

signed main(){
	LonggVuz();
	
	tc(){
		ms(vis, 0); ok = 0;
		cin >> n;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				cin >> a[i][j];
			}
		}run(1, 1, "");
		if(!ok) cout << -1;
		cout << el;
	}
	
	End();
}