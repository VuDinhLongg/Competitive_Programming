#include <bits/stdc++.h>
using namespace std;

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define len(x) (int)x.size()
#define int long long
#define mxn 200'007

struct FenwickTree{
	int n; vector<int> bit;
	FenwickTree(){}
	FenwickTree(int _n){
		n = _n;
		bit.assign(n + 5, 0);
	}
	void update(int x, int v){
		for(; 1 <= x and x <= n; x += x & -x) maxi(bit[x], v);
	}
	int query(int x){
		int r = 0;
		for(; 1 <= x and x <= n; x -= x & -x) maxi(r, bit[x]);
		return r;
	}
	int query(int l, int r){
		return l <= r ? query(r) - query(l - 1) : 0;
	}
};

int n, a[mxn], ans[mxn];
vector<int> g[mxn];
FenwickTree bit(2e5);

void zip(vector<int> &a, int l, int r){
	vector<int> v; fo(i, l, r) v.push_back(a[i]); sort(all(v));
	v.erase(unique(all(v)), end(v));
	fo(i, l, r) a[i] = lower_bound(all(v), a[i]) - begin(v) + 1;
}

void zip(int a[], int l, int r){
	vector<int> v; fo(i, l, r) v.push_back(a[i]); sort(all(v));
	v.erase(unique(all(v)), end(v));
	fo(i, l, r) a[i] = lower_bound(all(v), a[i]) - begin(v) + 1;
}

void swap(FenwickTree &a, FenwickTree &b){
	swap(a.bit, b.bit);
}

void dfs(int u, int p){
	int tmp = bit.query(a[u] - 1);
	int pre = bit.query(a[u]);
	vector<pair<int, int>> vec;
	if(tmp + 1 > pre){
		for(int idx = a[u]; idx <= n; idx += idx & -idx) vec.push_back({idx, bit.bit[idx]});
		bit.update(a[u], tmp + 1);
	}
	ans[u] = bit.query(1, n);
	for(int &v : g[u]) if(v != p){
		dfs(v, u);
	}
	if(tmp + 1 > pre){
		for(auto &[idx, val] : vec) bit.bit[idx] = val;
	}
}

void solve(){
	cin >> n;
	fo(i, 1, n) cin >> a[i];
	zip(a, 1, n);
	fo(i, 2, n){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	fo(u, 1, n) cout << ans[u], el;
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	#define file "LonggVuz"
	if(fopen(file".inp", "r")){
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	}
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}