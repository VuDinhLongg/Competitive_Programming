/*======================
   Author : @LonggVuz
======================*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define yay(...) 2005
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
#define mxn 1'000'007

int d, dp[20][2][2], len;
vector<int> a;

int rev(int n){
	int r = 0;
	while(n){
		r = r * 10 + n % 10;
		n /= 10;
	}
	return r;
}

int memo(int idx, int l, int r){
	if(idx == len / 2){
		if(len & 1){
			return a[idx] + l == r * 10 ? 10 : 0;
		}
		return l == r;
	}
	int &res = dp[idx][l][r];
	if(res != -1) return res;
	res = 0;
	int ridx = len - 1 - idx;
	int lim = 0;
	if(idx == 0) lim = 1;
	fo(i, lim, 9) fo(j, lim, 9) fo(nr, 0, 1){
		if((i + a[idx] + l) % 10 == j and i == (j + a[ridx] + nr) % 10 and (j + a[ridx] + nr) / 10 == r){
			res += memo(idx + 1, (i + a[idx] + l) / 10, nr);
		}
	}
	return res;
}

inline void LonggVuz(){
	cin >> d;
	if(d % 9) ret(0);
	while(d){
		a.push_back(d % 10);
		d /= 10;
	}
	int st = len(a);
	while(len(a) < 18) a.push_back(0);
	int res = 0;
	fo(i, st, 18){
		len = i;
		memset(dp, -1, sizeof dp);
		res += memo(0, 0, 0);
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) yay(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
