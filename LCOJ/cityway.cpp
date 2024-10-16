// https://luyencode.net/problem/cityway
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
#define int int32_t

const int mod = 1e9 + 7;
const int mxn = 1e5 + 7;

int n, m, r[mxn];

int get(int u){
	if(r[u] == u) return u;
	return r[u] = get(r[u]);
}

void LonggVuz(){
	cin >> n >> m;
	for(int i=1; i<=n; i++) r[i] = i;
	for(int i=0; i<m; i++){
		int x, y; cin >> x >> y;
		x = get(x); y = get(y);
		r[y] = x;
	}
	set<int> s;
	for(int i=1; i<=n; i++){
		int x = get(i);
		s.is(x);
	}
	cout << len(s) - 1;
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
