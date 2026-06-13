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
#define pii pair<int, int>
#define fi first
#define se second

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

int n, q;
vector<int> a[1005];

int dist(int x, int y){
	bool vis[n + 5] = {0};
	queue<pii> q;
	q.push({x, 0});
	vis[x] = 1;
	while(len(q)){
		auto x = q.front(); q.pop();
		int u = x.fi, d = x.se;
		if(u == y) return d;
		for(int &v : a[u]){
			if(!vis[v]){
				q.push({v, d + 1});
				vis[v] = 1;
			}
		}
	}return oo;
}

void LonggVuz(){
	cin >> n;
	for(int i=1; i<n; i++){
		int x, y; cin >> x >> y;
		a[x].pb(y);
		a[y].pb(x);
	}
	cin >> q;
	while(q--){
		int x, y; cin >> x >> y;
		cout << dist(x, y) << el;
	}
	for(int i=1; i<=n; i++) a[i].clear();
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}