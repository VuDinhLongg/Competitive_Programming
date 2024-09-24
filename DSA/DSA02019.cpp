// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Legendary Grandmaster
void End(){
    cerr << "=> Thời gian code chạy: ";
    cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define Sonic() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define ms(a, x) memset(a, x, sizeof(a))
#define bit(n, x) (n >> x & 1)
#define pb push_back
#define is insert
#define el '\n'
#define ld long double
#define int int32_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int n, m, vis[22][22], res;
vector<int> a[22];

void dfs(int u, int cnt){
	res = max(res, cnt - 1);
	for(int &v : a[u]){
		if(!vis[u][v] && !vis[v][u]){
			vis[u][v] = vis[v][u] = 1;
			dfs(v, cnt + 1);
			vis[u][v] = vis[v][u] = 0;
		}
	}
}

void LonggVuz(){
	cin >> n >> m;
	while(m--){
		int x, y; cin >> x >> y;
		++x; ++y;
		a[x].pb(y);
		a[y].pb(x);
	}res = 0;
	for(int i=1; i<=n; i++){
		ms(vis, 0);
		dfs(i, 1);
	}cout << res << el;
	for(int i=1; i<=n; i++) a[i].clear();
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}