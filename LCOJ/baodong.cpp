// https://luyencode.net/problem/baodong
// LonggVuz
#include<bits/stdc++.h>
using namespace std;
// Think twice, code once ^.^
void End(){
    cerr << "=> Smoothly Finished! Time taken: ";
    cerr << (0.001 * clock()) << "s" << string(25, '\t');
}
#define Sonic() cin.tie(0) -> sync_with_stdio(0)
#define out(x) return cout << x << el, void()
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

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e3 + 7;

int n, a[mxn][mxn], r[mxn];
vector<int> v[mxn];

int get(int u){
	if(r[u] == u) return u;
	return r[u] = get(r[u]);
}

void LonggVuz(){
	cin >> n;
	for(int i=1; i<=n; i++) r[i] = i;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			if(a[i][j]){
				int x = get(i), y = get(j);
				if(x == y) continue;
				r[x] = y;
			}
		}
	}
	for(int i=1; i<=n; i++){
		int x = get(i);
		v[x].pb(i);
	}
	for(int i=1; i<=n; i++){
		int l = len(v[i]);
		for(int j=0; j<l-1; j++){
			for(int k=j+1; k<l; k++){
				a[v[i][j]][v[i][k]] = a[v[i][k]][v[i][j]] = 1;
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout << a[i][j] << ' ';
		}cout << el;
	}
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
