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
#define mask(n) (1ll << (n))
#define bit(n, i) ((n) >> (i) & 1)
#define one(n) __builtin_popcountll(n)
#define clz(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctzll(n)

struct node{
	int u, v, w;
};

int L, n;
vector<node> res;

inline void LonggVuz(){
	cin >> L;
	while(mask(n + 1) <= L) ++n;
	fo(i, 0, n - 1){
		res.push_back({i, i + 1, 0});
		res.push_back({i, i + 1, mask(i)});
	}
	int rem = L - mask(n), w = mask(n);
	dbg(n, rem, w);
	fd(i, n - 1, 0) if(bit(rem, i)){
		res.push_back({i, n, w});
		w += mask(i);
	}
	cout << n + 1 << ' ' << len(res), el;
	for(auto &[u, v, w] : res){
		cout << u + 1 << ' ' << v + 1 << ' ' << w, el;
	}
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}