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
	int find(int k){
		int pos = 0, cur = 0;
		fd(i, 22, 0){
			int nxt = pos + (1 << i);
			if(nxt <= n and cur + bit[nxt] < k){
				cur += bit[nxt];
				pos = nxt;
			}
		}
		return pos + 1;
	}
};

int n, k, a[mxn], offset = 1e6 + 1;

inline void LonggVuz(){
	cin >> n >> k;
	fo(i, 1, n){
		cin >> a[i];
		a[i] += offset;
	}
	FenwickTree bit(1e6 + offset);
	fo(i, 1, k){
		bit.update(a[i], 1);
	}
	cout << bit.find((k + 1) / 2) - offset << ' ';
	fo(i, k + 1, n){
		bit.update(a[i - k], -1);
		bit.update(a[i], 1);
		cout << bit.find((k + 1) / 2) - offset << ' ';
	}
	el;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(1) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}