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

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 200'007

struct node{
	int op, cl;
};

int n, q;
string s;
node seg[mxn * 4];

node merge(const node &l, const node &r){
	node o;
	int tmp = min(l.op, r.cl);
	o.op = l.op + r.op - tmp;
	o.cl = l.cl + r.cl - tmp;
	return o;
}

void update(int id, int l, int r, int i, char c){
	if(l == r){
		if(c == '(') seg[id] = {1, 0};
		else seg[id] = {0, 1};
		return;
	}
	int m = l + r >> 1;
	if(i <= m) update(id * 2, l, m, i, c);
	else update(id * 2 + 1, m + 1, r, i, c);
	seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

node query(int id, int l, int r, int u, int v){
	if(r < u or v < l) return {0, 0};
	if(u <= l and r <= v) return seg[id];
	int m = l + r >> 1;
	return merge(query(id * 2, l, m, u, v), query(id * 2 + 1, m + 1, r, u, v));
}

inline void LonggVuz(){
	cin >> n >> q >> s;
	s = " " + s;
	fo(i, 1, n) update(1, 1, n, i, s[i]);
	while(q--){
		int t, l, r; cin >> t >> l >> r;
		if(t == 1){
			if(s[l] != s[r]){
				swap(s[l], s[r]);
				update(1, 1, n, l, s[l]);
				update(1, 1, n, r, s[r]);
			}
		}else{
			node ans = query(1, 1, n, l, r);
			if(ans.op == 0 and ans.cl == 0) cout << "Yes\n";
			else cout << "No\n";
		}
	}
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}