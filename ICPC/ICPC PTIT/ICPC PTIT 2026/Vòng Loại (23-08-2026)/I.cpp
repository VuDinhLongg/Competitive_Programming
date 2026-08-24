#include <bits/stdc++.h>
using namespace std;

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define len(x) (int)x.size()
#define int long long
#define mxn 1'000'007



void solve(){
	string s; cin >> s;
	int res = 0;
	for(char &c : s){
		res = res * 26 + (c - 'A' + 1);
	}
	cout << res;
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	#define file "LonggVuz"
	if(fopen(file".inp", "r")){
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	}
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}