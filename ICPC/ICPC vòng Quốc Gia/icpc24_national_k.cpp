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

bool check(int x, int l, int r){
	fo(i, l, r) if(x % i == 0) return 1;
	return 0;
}

inline void LonggVuz(){
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    if(a == b){
    	fo(t, 1, n){
    		fo(i, 0, n - 1 - a + 1) if(s[i] == '0'){
	    		fo(j, i, i + a - 1) s[j] ^= 1;
	    	}
    	}
    	for(char &c : s) if(c == '0') out("NO");
    	cout << "YES";
    }else{
    	fo(i, 0, n - 1 - a + 1) if(s[i] == '0'){
    		fo(j, i, i + a - 1) s[j] ^= 1;
    	}
    	fo(i, 0, n - 1) if(s[i] == '0'){
    		if(a <= i) s[i] = '1';
    		else if(a <= n - i - 1) s[i] = '1';
    		// else{
    		// 	int j = i;
    		// 	while(j < n and s[j] == s[i]){
    		// 		++j;
    		// 		if(j - i == a) break;
    		// 	}
    		// 	int need = (j - i) + (a - (j - i)) * 2;
    		// 	if(check(need, a, b) and 0 <= j - a + 1 and i + a - 1 < n){
    		// 		fo(k, i, j - 1) s[k] = '1';
    		// 	}
    		// }
    	}
    	for(char &c : s) if(c == '0') out("NO");
    	cout << "YES";
    }
    el;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(1) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}