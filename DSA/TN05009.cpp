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
#define int intmax_t
#define ld long double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int n, m;
vector<int> a[1005];
bool vis[1005];

bool dfs(int u, int par, vector<int> &ve){
	vis[u] = 1;
	for(int &v : a[u]){
		if(!vis[v]){
			ve.pb(v);
			if(dfs(v, u, ve)) return 1;
			ve.pop_back();
		}else if(v != par && v == 1) return 1;
	}return 0;
}

signed main(){
	LonggVuz();
	
	tc(){
		cin >> n >> m;
		while(m--){
			int x, y; cin >> x >> y;
			a[x].pb(y); a[y].pb(x);
		}
		for(int i=1; i<=n; i++) sort(all(a[i]));
		vector<int> v;
		v.pb(1);
		if(dfs(1, 0, v)){
			v.pb(1);
			for(int &i : v) cout << i << ' '; cout << el;
		}else cout << "NO\n";
		for(int i=1; i<=n; i++) a[i].clear(), vis[i] = 0;
	}
	
	End();
}