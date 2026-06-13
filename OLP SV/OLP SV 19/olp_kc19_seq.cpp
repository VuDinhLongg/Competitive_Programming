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
#define fix(x) fixed << setprecision(x)
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 100'007

int n, q, a[mxn], b[mxn], c[mxn];

struct RMQ{
	int n;
	vector<vector<int>> rmq;
	RMQ(const vector<int> &a, int _n){
		n = _n;
		rmq.resize(lg2(n) + 1, vector<int>(n + 5));
		for(int i = 1; i <= n; ++i) rmq[0][i] = a[i];
		for(int k = 1; (1<<k) <= n; ++k) for(int i = 1; i + (1<<k) - 1 <= n; ++i)
			rmq[k][i] = gcd(rmq[k - 1][i], rmq[k - 1][i + (1<<(k-1))]);
	}
	RMQ(const int a[], int _n){
		n = _n;
		rmq.resize(lg2(n) + 1, vector<int>(n + 5));
		for(int i = 1; i <= n; ++i) rmq[0][i] = a[i];
		for(int k = 1; (1<<k) <= n; ++k) for(int i = 1; i + (1<<k) - 1 <= n; ++i)
			rmq[k][i] = gcd(rmq[k - 1][i], rmq[k - 1][i + (1<<(k-1))]);
	}
	int lg2(int n){ return 63 - __builtin_clzll(n); }
	int query(int l, int r){
		if(l < 1 or r > n or l > r) return 1e18;
		int k = lg2(r - l + 1);
		return gcd(rmq[k][l], rmq[k][r - (1<<k) + 1]);
	}
};

inline void LonggVuz(){
    cin >> n >> q;
    fo(i, 1, n) cin >> a[i];
    fo(i, 1, n) cin >> b[i];
    fo(i, 1, n) c[i] = abs(a[i] - b[i]);
    RMQ rmq(c, n);
    while(q--){
    	int l, r; cin >> l >> r;
    	cout << rmq.query(l, r), el;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
