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

const int mod = 1e9 + 7;

int t, n, p[mxn], dp[mxn];

int Pow(int a, int n, int m = 1e9 + 7){
	int r = 1; a %= m;
	for(; n; n >>= 1, a = a * a % m) if(n & 1) r = r * a % m;
	return r;
}

void solve1(){
	fo(i, 1, n){
		int x = i;
		while(x > 1){
			++dp[p[x]];
			x /= p[x];
		}
	}
	int res = 1;
	fo(i, 1, n) if(dp[i] > 1){
		int j = dp[i] / 2 * 2;
		res *= Pow(i, j);
		res %= mod;
	}
	cout << res;
}

void solve2(){
	fo(i, 1, n){
		int x = i;
		while(x > 1){
			++dp[p[x]];
			x /= p[x];
		}
	}
	vector<int> v;
	fo(i, 1, n) if(dp[i] > 0){
		if(dp[i] & 1) v.push_back(i);
	}
	int cnt = 0, l = 0, r = v.size() - 1;
	while(l <= r){
		if(v[l] * v[r] <= n){
			++cnt;
			++l; --r;
		}else{
			++cnt;
			--r;
		}
	}
	cout << n - cnt;
}

inline void LonggVuz(){
    fo(i, 2, 1e6) if(p[i] == 0){
		for(int j=i; j<=1e6; j+=i){
			if(p[j] == 0) p[j] = i;
		}
	}
    cin >> t >> n;
    if(t == 1) solve1();
    else solve2();
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}