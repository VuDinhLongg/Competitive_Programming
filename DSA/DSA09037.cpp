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
#define int int64_t
#define ld long double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int k, n, m, dem[105][1005];
bool vis[1005];
vector<int> a[1005];

void dfs(int i, int u){
	dem[i][u] = dem[i-1][u] + 1;
	vis[u] = 1;
	for(int &v : a[u]){
		if(!vis[v]){
			dfs(i, v);
		}
	}
}

signed main(){
	LonggVuz();
	
	cin >> k >> n >> m;
	int p[k+5];
	for(int i=1; i<=k; i++){
		cin >> p[i];
	}
	while(m--){
		int x, y; cin >> x >> y;
		a[x].pb(y);
	}
	for(int i=1; i<=k; i++){
		ms(vis);
		dfs(i, p[i]);
	}int res = 0;
	for(int i=1; i<=n; i++){
		if(dem[k][i] == k) ++res;
	}cout << res;
	
	End();
}