// LonggVuz
#include<bits/stdc++.h>
using namespace std;
// ☞ Think twice, code once ☜
void End(){
    cerr << "=> Smoothly Finished! Time taken: ";
    cerr << (0.001 * clock()) << "s" << string(25, '\t');
}
#define Sonic() cin.tie(0) -> sync_with_stdio(0)
#define out(x) return cout << x, void()
#define fix(x) fixed << setprecision(x)
#define all(x) begin(x), end(x)
#define len(x) (int)x.size()
#define ms(a, x) memset(a, x, sizeof(a))
#define bit(n, x) (n >> x & 1)
#define pb push_back
#define is insert
#define el '\n'
#define ld long double
#define int int64_t
#define pe pair<int, int>
#define fi first
#define se second

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

int n, m, u;
vector<int> a[1005];
bool vis[1005];
vector<pe> ve;

void LonggVuz(){
	cin >> n >> m >> u;
	while(m--){
		int x, y; cin >> x >> y;
		a[x].pb(y);
		a[y].pb(x);
	}
	queue<int> q;
	q.push(u);
	vis[u] = 1;
	while(len(q)){
		int d = q.front(); q.pop();
		for(int &v : a[d]){
			if(!vis[v]){
				vis[v] = 1;
				ve.pb({d, v});
				q.push(v);
			}
		}
	}
	if(len(ve) == n - 1){
		for(auto &i : ve){
			cout << i.fi << ' ' << i.se << el;
		}
	}else cout << "-1\n";
	ms(a, {});
	ms(vis, 0);
	ve.clear();
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}