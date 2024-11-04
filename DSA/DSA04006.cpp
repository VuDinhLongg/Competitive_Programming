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

int length(int n){
	if(n <= 1) return 1;
	return 1 + 2 * length(n / 2);
}

int cal(int n, int l, int r, int u, int v){
	if(r < u or v < l) return 0;
	if(u <= l and r <= v) return n;
	int mid = (l + r) / 2;
	int res = cal(n / 2, l, mid - 1, u, v) + cal(n / 2, mid + 1, r, u, v);
	if(u <= mid and mid <= v) res += n % 2;
	return res;
}

void LonggVuz(){
	int n, l, r; cin >> n >> l >> r;
	cout << cal(n, 1, length(n), l, r) << el;
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
