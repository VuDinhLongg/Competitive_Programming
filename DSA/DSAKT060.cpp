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

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

int n, q;
string a;
// AC in 0.40s
void LonggVuz(){
	cin >> a >> q;
	n = len(a);
	a = "@" + a;
	while(q--){
		char c; cin >> c;
		if(c == 'q'){
			int l, r; cin >> l >> r;
			bool ok = 1;
			while(l < r){
				if(a[l] != a[r]){
					ok = 0; break;
				}
				++l; --r;
			}
			if(ok) cout << "YES\n";
			else cout << "NO\n";
		}else{
			int pos; char x; cin >> pos >> x;
			a[pos] = x;
		}
	}
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
