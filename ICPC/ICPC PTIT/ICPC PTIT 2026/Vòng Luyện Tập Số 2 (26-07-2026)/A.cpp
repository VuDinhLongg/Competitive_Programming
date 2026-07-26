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
#define mxn 1'000'007
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
		bit.assign(n + 5, 0);
	}
	void update(int x, int v){
		for(; 1 <= x and x <= n; x += x & -x) bit[x] += v;
	}
	int query(int x){
		int r = 0;
		for(; 1 <= x and x <= n; x -= x & -x) r += bit[x];
		return r;
	}
	int query(int l, int r){
		return l <= r ? query(r) - query(l - 1) : 0;
	}
};

int n, k, x[mxn], y[mxn];
pii a[mxn];

int calc(int d){
	int res = 0;
	{
		int l = 1;
		fo(r, 1, n){
			while(l < r and x[r] - x[l] > d) ++l;
			res += r - l;
		}
	}
	{
		int l = 1;
		fo(r, 1, n){
			while(l < r and y[r] - y[l] > d) ++l;
			res += r - l;
		}
	}
	{
		int lim = 1e5 + 1;
		FenwickTree bit(lim);
		int l = 1;
		fo(r, 1, n){
			while(l < r and a[r].fi - a[l].fi > d){
				bit.update(a[l].se, -1);
				++l;
			}
			res -= bit.query(max(a[r].se - d, 1ll), min(a[r].se + d, lim));
			bit.update(a[r].se, 1);
		}
	}
	dbg(d, res);
	return res;
}

inline void LonggVuz(){
	cin >> n >> k;
	fo(i, 1, n){
		cin >> x[i] >> y[i];
		++x[i];
		++y[i];
		a[i] = {x[i], y[i]};
	}
	sort(x+1, x+n+1);
	sort(y+1, y+n+1);
	sort(a+1, a+n+1);
	int l = -1, r = 1e5;
	while(r - l > 1){
		int mid = l + r >> 1;
		if(calc(mid) >= k) r = mid;
		else l = mid;
	}
	cout << r;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}