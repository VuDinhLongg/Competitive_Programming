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

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e3 + 7;

int n;
vector<int> a[mxn];
bool vis[mxn];
vector<vector<int>> res;

void run(int u, vector<int> ve){
	vis[u] = 1;
	ve.pb(u);
	bool ok = 0;
	for(int &v : a[u]){
		if(!vis[v]){
			ok = 1;
			run(v, ve);
		}
	}
	if(!ok){
		res.pb(ve);
		ve.pop_back();
	}
}

bool cmp(vector<int> a, vector<int> b){
	return a.back() < b.back();
}

void LonggVuz(){
	ms(vis, 0);
	cin >> n;
	for(int i=1; i<n; i++){
		int x, y; cin >> x >> y;
		a[x].pb(y);
	}
	run(1, {});
	sort(all(res), cmp);
	for(auto &v : res){
		for(int &i : v){
			cout << i << ' ';
		}cout << el;
	}res.clear();
	for(int i=1; i<=n; i++) a[i].clear();
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}