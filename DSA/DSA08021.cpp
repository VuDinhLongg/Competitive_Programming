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
#define pii pair<int, int>

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int n, m, a[1005][1005];
bool vis[1005][1005];

void bfs(int i, int j){
	ms(vis, 0);
	queue<pair<pii, int>> q;
	q.push({{i, j}, 0});
	while(!q.empty()){
		auto x = q.front(); q.pop();
		i = x.fi.fi; j = x.fi.se;
		int b = x.se;
		if(i == n && j == m){
			cout << b << el; return;
		}vis[i][j] = 1;
		if(j + a[i][j] <= m && !vis[i][j + a[i][j]]){
			q.push({{i, j + a[i][j]}, b + 1});
		}
		if(i + a[i][j] <= n && !vis[i + a[i][j]][j]){
			q.push({{i + a[i][j], j}, b + 1});
		}
	}cout << "-1\n";
}

signed main(){
	LonggVuz();
	
	tc(){
		cin >> n >> m;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				cin >> a[i][j];
			}
		}bfs(1, 1);
	}
	
	End();
}