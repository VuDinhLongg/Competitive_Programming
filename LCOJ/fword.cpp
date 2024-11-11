// https://luyencode.net/problem/fword
// LonggVuz
#include<bits/stdc++.h>
using namespace std;
// Think twice, code once ^.^
void End(){
    cerr << "=> Smoothly Finished! Time taken: ";
    cerr << (0.001 * clock()) << "s" << string(25, '\t');
}
#define Sonic() cin.tie(NULL) -> sync_with_stdio(false);
#define fix(x) fixed << setprecision(x)
#define all(x) begin(x), end(x)
#define len(x) (int)x.size()
#define out(x) return cout << x << el, void()
#define ms(a, x) memset(a, x, sizeof(a))
#define bit(n, x) (n >> x & 1)
#define pb push_back
#define is insert
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 2e5 + 7;

int n, m, k, x, f[505], mu[505];
string a, t[505];

void LonggVuz(){
	cin >> n >> m >> k >> x >> a;
	for(int i=0; i<m; i++){
		cin >> t[i];
		t[i].pb('0');
		sort(all(t[i]));
	}
	for(int i=0; i<m; i++) f[i] = 1;
	mu[m - 1] = 1;
	for(int i=m-2; i>=0; i--){
		if(mu[i + 1] > x / k) break;
		mu[i] = mu[i + 1] * k;
	}
	for(int i=0; i<=m-2; i++){
		if(mu[i] > 0){
			f[i] += x / mu[i];
			if(x % mu[i] == 0) --f[i];
			x %= mu[i];
		}
	}
	f[m - 1] = x % k;
	if(f[m - 1] == 0) f[m - 1] = k;
	int id = 0;
	for(int i=0; i<n; i++){
		if(a[i] == '#'){
			a[i] = t[id][f[id]];
			++id;
		}
	}cout << a;
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
