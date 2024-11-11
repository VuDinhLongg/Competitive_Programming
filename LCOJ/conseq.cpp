// https://luyencode.net/problem/conseq
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
#define len(x) (int)size(x)
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

int ps[mxn];
map<int, int> dem;

void LonggVuz(){
	int n; cin >> n;
	int a[n+5];
	for(int i=1; i<=n; i++){
		cin >> a[i];
		ps[i] = ps[i - 1] + a[i];
	}
	int res = 0;
	for(int i=1; i<=n; i++){
		int mi = a[i], mx = a[i], pos = n;
		for(int j=i; j<=n; j++){
			++dem[a[j]]; 
			if(dem[a[j]] > 1){
				pos = j; break;
			}
			mi = min(mi, a[j]);
			mx = max(mx, a[j]);
			if((mx + mi) * (mx - mi + 1) == (ps[j] - ps[i - 1]) * 2){
				++res;
			}
		}
		for(int j=i; j<=pos; j++) dem[a[j]] = 0;
	}cout << res;
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
