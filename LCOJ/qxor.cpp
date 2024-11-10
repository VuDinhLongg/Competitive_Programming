// https://luyencode.net/problem/qxor
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
const int mxn = 1e5 + 7;

int n, q, a[mxn], f[mxn * 4];

void update(int id, int l, int r, int pos, int val){
	if(l == r){
		f[id] ^= val; return;
	}int m = (l + r) / 2;
	if(pos <= m) update(id * 2, l, m, pos, val);
	else update(id * 2 + 1, m + 1, r, pos, val);
	f[id] = f[id * 2] ^ f[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v){
	if(r < u or v < l) return 0;
	if(u <= l and r <= v) return f[id];
	int m = (l + r) / 2;
	return get(id * 2, l, m, u, v) ^ get(id * 2 + 1, m + 1, r, u, v);
}

void LonggVuz(){
	cin >> n >> q;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		update(1, 1, n, i, a[i]);
	}
	while(q--){
		int t, x, y; cin >> t >> x >> y;
		if(t == 1){
			update(1, 1, n, x, y);
		}else cout << get(1, 1, n, x, y) << el;
	}
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
