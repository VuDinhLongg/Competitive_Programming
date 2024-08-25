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

int n, m, x;
vector<int> a[1005];
bool vis[1005];

void bfs(){
	ms(vis, 0);
	queue<int> q;
	q.push(x); vis[x] = 1;
	while(!q.empty()){
		int u = q.front(); q.pop();
		cout << u << ' ';
		for(int v : a[u]){
			if(!vis[v]){
				vis[v] = 1;
				q.push(v);
			}
		}
	}cout << el;
}

signed main(){
	LonggVuz();
	
	tc(){
		cin >> n >> m >> x;
		while(m--){
			int u, v; cin >> u >> v;
			a[u].pb(v);
		}bfs();
		for(int i=1; i<=n; i++) a[i].clear();
	}
	
	End();
}