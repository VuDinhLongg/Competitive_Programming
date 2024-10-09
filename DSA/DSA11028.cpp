// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Legendary Grandmaster
void End(){
    cerr << "=> Smoothly Finished! Time taken: ";
    cerr << (0.001 * clock()) << "s" << string(25, '\t');
}
#define Sonic() cin.tie(NULL) -> sync_with_stdio(false);
#define fix(x) fixed << setprecision(x)
#define all(x) begin(x), end(x)
#define len(x) (int)x.size()
#define gel(x) getline(cin >> ws, x)
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
const int mxn = 1e5 + 7;

int n;
vector<int> a[mxn];
bool vis[mxn];

int run(int s){
	int res = -1;
	queue<pii> q;
	q.push({s, 0});
	vis[s] = 1;
	while(!q.empty()){
		pii x = q.front(); q.pop();
		int u = x.fi, d = x.se;
		for(int &v : a[u]){
			if(!vis[v]){
				vis[v] = 1;
				q.push({v, d + 1});
				res = max(res, d + 1);
			}
		}
	}return res;
}

void LonggVuz(){
	ms(vis, 0);
	cin >> n;
	for(int i=1; i<n; i++){
		int x, y; cin >> x >> y;
		a[x].pb(y);
	}
	cout << run(1) << el;
	for(int i=1; i<=n; i++) a[i].clear();
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}