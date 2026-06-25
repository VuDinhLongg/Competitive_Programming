/*======================
   Author : @LonggVuz
======================*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define orz(...) 2005
#endif

#define el cout << '\n'
#define all(x) begin(x), end(x)
#define len(x) (x).size()
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 200'007

int n, q, a[mxn], ok[mxn][10];
int seg[10][mxn * 4];

void prepare(){
	fo(i, 1, 2e5) fo(j, 1, 9){
		if(ok[i / 10][j] or i % 10 == j) ok[i][j] = 1;
	}
}

void update(int id, int l, int r, int i, int c, int j){
	if(l == r){
		seg[j][id] = c;
		if(ok[i][j] or i % j == 0) seg[j][id] = c * 2;
		return;
	}
	int m = l + r >> 1;
	if(i <= m) update(id * 2, l, m, i, c, j);
	else update(id * 2 + 1, m + 1, r, i, c, j);
	seg[j][id] = seg[j][id * 2] + seg[j][id * 2 + 1];
}

int query(int id, int l, int r, int u, int v, int j){
	if(r < u or v < l) return 0;
	if(u <= l and r <= v) return seg[j][id];
	int m = l + r >> 1;
	return query(id * 2, l, m, u, v, j) + query(id * 2 + 1, m + 1, r, u, v, j);
}

inline void LonggVuz(){
	prepare();
    cin >> n >> q;
    fo(i, 1, n){
    	cin >> a[i];
    	fo(j, 1, 9) update(1, 1, n, i, a[i], j);
    }
    while(q--){
    	int t; cin >> t;
    	if(t == 1){
    		int i, c; cin >> i >> c;
    		fo(j, 1, 9) update(1, 1, n, i, c, j);
    		a[i] = c;
    	}else{
    		int l, r, k; cin >> l >> r >> k;
    		cout << query(1, 1, n, l, r, k), el;
    	}
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
