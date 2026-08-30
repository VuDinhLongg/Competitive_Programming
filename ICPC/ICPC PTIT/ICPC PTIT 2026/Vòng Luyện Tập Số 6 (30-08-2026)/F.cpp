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
#define rep(i, n) fo(i, 0, n - 1)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define int long long
#define mxn 200'007
#define ai3 array<int, 3>
#define ai4 array<int, 4>
#define pii pair<int, int>
#define fi first
#define se second

struct FenwickTree{
	int n; vector<int> bit;
	FenwickTree(){}
	FenwickTree(int _n){
		n = _n;
		bit.assign(n + 5, 1e18);
	}
	void update(int x, int v){
		for(; 1 <= x and x <= n; x += x & -x) mini(bit[x], v);
	}
	int query(int x){
		int r = 1e18;
		for(; 1 <= x and x <= n; x -= x & -x) mini(r, bit[x]);
		return r;
	}
	int query(int l, int r){
		return l <= r ? query(r) - query(l - 1) : 0;
	}
};

int n;
ai3 a[mxn];

inline void LonggVuz(){
	cin >> n;
	vector<int> val;
	fo(i, 1, n){
		rep(j, 3) cin >> a[i][j], val.push_back(a[i][j]);
		sort(all(a[i]));
	}
	sort(a+1, a+n+1);
	sort(all(val));
	val.erase(unique(all(val)), end(val));
	fo(i, 1, n) rep(j, 3){
		a[i][j] = lower_bound(all(val), a[i][j]) - begin(val) + 1;
	}
	fo(i, 1, n) dbg(a[i]);
	FenwickTree bit(n * 3);
	int j = 1;
	fo(i, 1, n){
		while(j <= n and a[j][0] < a[i][0]){
			bit.update(a[j][1], a[j][2]);
			++j;
		}
		if(bit.query(a[i][1] - 1) < a[i][2]) ret("Yes");
	}
	ret("No");
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "LonggVuz"
	if(fopen(name".inp", "r")){
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}