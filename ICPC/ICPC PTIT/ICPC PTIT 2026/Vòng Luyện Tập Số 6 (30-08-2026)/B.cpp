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
#define mxn 1'000'007

int n, x[105], y[105];

bool check(int i, int j, int k){
	int x1 = x[i] - x[j];
	int y1 = y[i] - y[j];
	int x2 = x[i] - x[k];
	int y2 = y[i] - y[k];
	return x1 * y2 == x2 * y1;
}

inline void LonggVuz(){
	cin >> n;
	fo(i, 1, n) cin >> x[i] >> y[i];
	fo(i, 1, n) fo(j, i + 1, n) fo(k, j + 1, n) if(check(i, j, k)) ret("Yes");
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