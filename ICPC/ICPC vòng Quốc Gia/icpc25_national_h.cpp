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
#define mxn 200'007

int n, k;

int cal(int l0){
	int z = n - k;
	int seg = z / l0 + (z % l0 > 0);
	if(seg == 1) return k;
	if(k < seg - 1) return -1e18;
	return k / (seg - 1);
}

inline void LonggVuz(){
    cin >> n >> k;
    int res = 1e18, l0 = 0;
    fo(i, 1, n - k){
    	int ans = i * (n + 1) - cal(i);
    	if(mini(res, ans)){
    		l0 = i;
    	}
    }
    if(l0 == 0) out(string(k, '1'));
    int cnt0 = (n - k) / l0 + ((n - k) % l0 > 0);
    int s1 = cal(l0);
    if(s1 == 0) out(string(n - k, '0'));
    fo(i, 1, cnt0){
    	if(i == 1){
    		if((n - k) % l0) fo(j, 1, (n - k) % l0) cout << 0;
    		else fo(j, 1, l0) cout << 0;
    		if(cnt0 > 1) fo(j, 1, k % (s1 * (cnt0 - 1))) cout << 1;
    	}else{
    		fo(j, 1, l0) cout << 0;
    	}
    	if(i < cnt0 or cnt0 == 1) fo(j, 1, s1) cout << 1;
    }
    el;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(1) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}