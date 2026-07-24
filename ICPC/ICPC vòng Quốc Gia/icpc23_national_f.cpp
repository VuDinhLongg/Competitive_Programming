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
#define mxn 200'007

int n, cnt[mxn][3];
string s;

inline void LonggVuz(){
	cin >> s;
	n = len(s);
	s = " " + s;
	string a = s;
	fo(i, 1, n){
		fo(j, 0, 2) cnt[i][j] = cnt[i - 1][j];
		if(s[i] == 'S') a[i] = 'R', ++cnt[i][0];
		else if(s[i] == 'P') a[i] = 'S', ++cnt[i][1];
		else a[i] = 'P', ++cnt[i][2];
	}
	auto calc = [&](int k){
		int res = 0, i = 1;
		while(i <= n){
			int j = i + k - 1;
			mini(j, n);
			int mx = 0;
			fo(k, 0, 2) maxi(mx, cnt[j][k] - cnt[i - 1][k]);
			res += mx;
			i = j + 1;
		}
		dbg(k, res);
		return res;
	};
	int res = 0, k = 0;
	fd(i, n, 2) if(maxi(res, calc(i))) k = i;
	cout << k, el;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(1) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
