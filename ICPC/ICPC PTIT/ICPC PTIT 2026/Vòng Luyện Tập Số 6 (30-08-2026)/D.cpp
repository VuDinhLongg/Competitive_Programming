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
#define mxn 300'007

int n, c, a[mxn];

inline void LonggVuz(){
	cin >> n >> c;
	fo(i, 1, n) cin >> a[i];
	int res = 0;
	fo(i, 1, n) res += a[i];
	int add = 0;
	if(c > 0){
		int s = 0, m = 0;
		fo(i, 1, n){
			s += a[i];
			maxi(add, (s - m) * (c - 1));
			mini(m, s);
		}
	}else{
		int s = 0, m = 0;
		fo(i, 1, n){
			s += a[i];
			maxi(add, (s - m) * (c - 1));
			maxi(m, s);
		}
	}
	cout << res + add;
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