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

int n, m, s, t;
vector<int> a[1005], v;
bool vis[1005], ok;

void dfs(int u){
	vis[u] = 1;
	if(u == t){
		ok = 1; return;
	}
	for(int &i : a[u]){
		if(!vis[i]){
			v.pb(i);
			dfs(i);
			if(ok) return;
			v.pop_back();
		}
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		ms(vis, 0); v.clear(); ok = 0;
		cin >> n >> m >> s >> t;
		while(m--){
			int x, y; cin >> x >> y;
			a[x].pb(y); a[y].pb(x);
		}v.pb(s); dfs(s);
		if(vis[t]){
			for(int &i : v){
				cout << i << ' ';
			}cout << el;
		}else cout << "-1\n";
		for(int i=1; i<=n; i++) a[i].clear();
	}
	
	End();
}