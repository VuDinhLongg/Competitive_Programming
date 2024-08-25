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

int n, m;
vector<int> a[1005];
vector<pii> ve;
bool mark[1005][1005], vis[1005];

void dfs(int u){
	vis[u] = 1;
	for(int v : a[u]){
		if(!vis[v] && !mark[u][v]) dfs(v);
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		ms(vis, 0);
		cin >> n >> m;
		while(m--){
			int u, v; cin >> u >> v;
			a[u].pb(v); a[v].pb(u);
			if(u > v) swap(u, v);
			ve.pb({u, v});
		}int mx = 0;
		for(int i=1; i<=n; i++){
			if(!vis[i]){
				dfs(i); ++mx;
			}
		}
		for(auto i : ve){
			mark[i.fi][i.se] = 1;
			mark[i.se][i.fi] = 1;
			bool ok = 1; int cnt = 0;
			ms(vis, 0);
			for(int j=1; j<=n; j++){
				if(!vis[j]){
					++cnt;
					if(cnt > mx){
						ok = 0; break;
					}dfs(j);
				}
			}if(!ok) cout << i.fi << ' ' << i.se << ' ';
			mark[i.fi][i.se] = 0;
			mark[i.se][i.fi] = 0;
		}ve.clear();
		for(int i=1; i<=n; i++) a[i].clear();
		cout << el;
	}
	
	End();
}