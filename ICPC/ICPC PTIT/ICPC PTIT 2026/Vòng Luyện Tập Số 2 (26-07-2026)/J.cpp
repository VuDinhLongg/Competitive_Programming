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
	int i, l, r, o;
};

int n, a[mxn], pos[mxn], pre[mxn], nxt[mxn];
int seg[mxn * 8], cnt[mxn * 8];

void prepare(){
	fo(i, 1, n) pos[i] = 0;
	fo(i, 1, n){
		pre[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	fo(i, 1, n) pos[i] = n + 1;
	fd(i, n, 1){
		nxt[i] = pos[a[i]];
		pos[a[i]] = i;
	}
}

void update(int id, int l, int r, int u, int v, int o){
	if(r < u or v < l) return;
	if(u <= l and r <= v){
		cnt[id] += o;
		if(cnt[id] > 0) seg[id] = r - l + 1;
		else seg[id] = seg[id * 2] + seg[id * 2 + 1];
		return;
	}
	int m = l + r >> 1;
	update(id * 2, l, m, u, v, o);
	update(id * 2 + 1, m + 1, r, u, v, o);
	if(cnt[id] > 0) seg[id] = r - l + 1;
	else seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

inline void LonggVuz(){
	cin >> n;
	fo(i, 1, n) cin >> a[i];
	prepare();
	vector<node> e;
	fo(i, 1, n){
		if(pre[i] + 1 <= n) e.push_back({pre[i] + 1, i, nxt[i] - 1, 1});
		if(i + 1 <= n) e.push_back({i + 1, i, nxt[i] - 1, -1});
	}
	sort(all(e), [](node &x, node &y){
		return x.i < y.i;
	});
	int res = 0, i = 0;
	while(i < len(e)){
		int j = i;
		while(j < len(e) and e[i].i == e[j].i){
			update(1, 1, n, e[j].l, e[j].r, e[j].o);
			++j;
		}
		if(j < len(e)) res += seg[1] * (e[j].i - e[i].i);
		else res += seg[1] * (n - e[i].i + 1);
		i = j;
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}