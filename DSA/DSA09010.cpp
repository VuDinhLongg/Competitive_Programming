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
#define int int32_t
#define ld long double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int n, m;
vector<int> a[1005], b[1005];
bool vis[1005];
stack<int> st;

void input(){
	cin >> n >> m;
	while(m--){
		int x, y; cin >> x >> y;
		a[x].pb(y);
		b[y].pb(x);
	}
}

void reset(){
	ms(vis, 0);
	while(!st.empty()) st.pop();
	for(int i=1; i<=n; i++) a[i].clear(), b[i].clear();
}

void dfs(int u){
	vis[u] = 1;
	for(int &v : a[u]){
		if(!vis[v]) dfs(v);
	}st.push(u);
}

void dfs2(int u){
	vis[u] = 1;
	for(int &v : b[u]){
		if(!vis[v]) dfs2(v);
	}
}

void solve(){
	for(int i=1; i<=n; i++){
		if(!vis[i]) dfs(i);
	}ms(vis, 0);
	int res = 0;
	while(!st.empty()){
		int u = st.top(); st.pop();
		if(!vis[u]){
			dfs2(u);
			++res;
			if(res == 2){
				cout << "NO\n"; return;
			}
		}
	}cout << "YES\n";
}

signed main(){
	LonggVuz();
	
	tc(){
		input();
		solve();
		reset();
	}
	
	End();
}