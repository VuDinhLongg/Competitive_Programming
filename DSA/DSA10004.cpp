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
const int mxn = 1e6 + 7;

int n, m, bac[1005];
vector<int> a[1005];

void LonggVuz(){
	cin >> n >> m;
	while(m--){
		int x, y; cin >> x >> y;
		a[x].pb(y);
		a[y].pb(x);
	}
	int le = 0;
	for(int i=1; i<=n; i++){
		bac[i] = len(a[i]);
		if(bac[i] % 2) ++le;
	}
	if(le == 0) cout << "2\n";
	else if(le == 2) cout << "1\n";
	else cout << "0\n";
	for(int i=1; i<=n; i++) a[i].clear();
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}