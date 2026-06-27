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
#define len(x) (x).size()
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 200'007

int calc(vector<int> &a, int n){
	if(n == 1) return a[1];
	int m = 20;
	while(m >= 0){
		if((1 << m) < n) break;
		--m;
	}
	m = 1 << m;
	int nn = n - m;
	vector<int> b(nn + 5);
	fo(i, 1, nn) b[i] = a[i] ^ a[i + m];
	return calc(b, nn);
}

inline void LonggVuz(){
    int n; cin >> n;
    vector<int> a(n + 5);
    fo(i, 1, n) cin >> a[i];
    cout << calc(a, n);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
