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
#define mxn 1'000'007

inline int GCD(int a, int b){ return b ? GCD(b, a % b) : a; }
inline int LCM(int a, int b){ return a / GCD(a, b) * b; }

int cal(int l, int r, int x){
	int st = (l / x + (l % x > 0));
	int en = r / x;
	return en - st + 1;
}

inline void LonggVuz(){
    int l, r, a, k;
	cin >> l >> r >> a >> k;
	a %= k;
	int t = k / gcd(a, k);
	int res = cal(l, r, t) + cal(l, r, k);
	int lcm = k / gcd(t, k);
	if(lcm <= r / t){
		lcm *= t;
		res -= cal(l, r, lcm);
	}
	cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}