/*======================
   Author : @LonggVuz
======================*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define yay(...) 2005
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
};

string s;
set<int> pos[300];
int a[mxn];

inline void LonggVuz(){
	cin >> s;
	int n = len(s);
	s = " " + s;
	fo(i, 1, n) pos[s[i]].insert(i);
	int odd = 0;
	fo(i, 'a', 'z') if(len(pos[i]) & 1) ++odd;
	if(odd > 1) ret(-1);
	int l = 1, r = n;
	fo(i, 1, n){
		if(len(pos[s[i]]) > 1){
			a[l] = *pos[s[i]].begin();
			a[r] = *pos[s[i]].rbegin();
			pos[s[i]].erase(pos[s[i]].begin());
			pos[s[i]].erase(--pos[s[i]].end());
			++l; --r;
		}else if(len(pos[s[i]]) == 1){
			a[(n + 1) / 2] = *pos[s[i]].begin();
			pos[s[i]].erase(pos[s[i]].begin());
		}
	}
	// fo(i, 1, n) cout << a[i] << ' '; el;
	int res = 0;
	FenwickTree bit(n);
	fo(i, 1, n){
		res += bit.query(a[i] + 1, n);
		bit.update(a[i], 1);
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) yay(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
