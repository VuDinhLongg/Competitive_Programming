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

int n, m, p[1005];
vector<int> a[1005];
bool vis[1005];

void bfs(int s, int t){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(u == t) break;
		for(int &v : a[u]){
			if(!vis[v]){
				vis[v] = 1;
				q.push(v);
				p[v] = u;
			}
		}
	}if(vis[t]){
		vector<int> v;
		int x = t;
		while(x != s){
			v.pb(x);
			x = p[x];
		}v.pb(s); reverse(all(v));
		for(int &i : v) cout << i << ' '; cout << el;
	}else cout << "-1\n";
}

signed main(){
	LonggVuz();
	
	tc(){
		ms(vis, 0); ms(p, 0);
		int s, t;
		cin >> n >> m >> s >> t;
		while(m--){
			int x, y; cin >> x >> y;
			a[x].pb(y); a[y].pb(x);
		}bfs(s, t);
		for(int i=1; i<=n; i++) a[i].clear();
	}
	
	End();
}