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
// #define int long long
#define mxn 500'007

int n, q, a[mxn];

bool check(int x, int p){
	while(x > 1 and x % p == 0) x /= p;
	return x == 1;
}

inline void LonggVuz(){
    cin >> n >> q;
    vector<int> val;
    fo(i, 1, n){
    	cin >> a[i];
    	if(check(a[i], 2) or check(a[i], 3) or check(a[i], 5)){
    		val.push_back(a[i]);
    	}
    }
    sort(all(val));
    auto calc = [&](int x){
    	int res = 0;
    	if(val.size()) res = upper_bound(all(val), x) - begin(val) - 1;
    	return res;
    };
    while(q--){
    	int l, r; cin >> l >> r;
    	cout << calc(r) - calc(l - 1), el;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
