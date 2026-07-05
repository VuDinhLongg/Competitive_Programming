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
#define len(x) (int)(x).size()
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 1'000'007

struct FenwickTree{
	int n; vector<int> bit;
	FenwickTree(int _n){
		n = _n;
		bit.assign(n + 5, 0);
	}
	void update(int x, int v){
		for(; x and x <= n; x += x & -x) bit[x] += v;
	}
	int query(int x){
		int r = 0;
		for(; x and x <= n; x -= x & -x) r += bit[x];
		return r;
	}
};

int n, a[mxn], pos[mxn], pre[mxn], suf[mxn];

inline void LonggVuz(){
	cin >> n;
	fo(i, 1, n){
		cin >> a[i];
		pos[a[i]] = i;
	}
	{
		FenwickTree bit(n);
		fo(i, 1, n){
			pre[i] = bit.query(n) - bit.query(pos[i]);
			bit.update(pos[i], 1);
		}
		fo(i, 1, n) pre[i] += pre[i - 1];
	}
	{
		FenwickTree bit(n);
		fd(i, n, 1){
			suf[i] = bit.query(pos[i] - 1);
			bit.update(pos[i], 1);
		}
		fd(i, n, 1) suf[i] += suf[i + 1];
	}
	int res = 1e18;
	fo(i, 1, n){
		dbg(i, pre[i], suf[i]);
		mini(res, pre[i - 1] + suf[i + 1]);
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(false) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
