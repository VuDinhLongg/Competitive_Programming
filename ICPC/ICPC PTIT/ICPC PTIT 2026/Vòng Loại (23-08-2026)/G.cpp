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

const int mod = 10;

int p[mxn], dp[mxn], f[mxn], mx[mxn];

int Pow(int a, int n){
	int r = 1;
	while(n){
		if(n & 1) r = r * a % mod;
		a = a * a % mod;
		n /= 2;
	}
	return r;
}

void prepare(){
	fo(i, 1, 1e6) p[i] = i;
	fo(i, 2, 1e3) if(p[i] == i){
		for(int j=i*i; j<=1e6; j+=i){
			if(p[j] == j) p[j] = i;
		}
	}
	dp[1] = f[1] = 1;
	fo(i, 2, 1e6){
		dp[i] = dp[i - 1];
		map<int, int> cur;
		int x = i;
		while(x > 1){
			++cur[p[x]];
			x /= p[x];
		}
		for(auto &[u, v] : cur){
			if(v > mx[u]){
				if(u != 2 and u != 5) dp[i] = dp[i] * Pow(u, v - mx[u]) % mod;
				mx[u] = v;
			}
		}
		int tmp = mx[2] - mx[5];
		f[i] = Pow(2, tmp);
	}
}

void solve(){
	int n; cin >> n;
	ret(dp[n] * f[n] % mod);
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	#define file "LonggVuz"
	if(fopen(file".inp", "r")){
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	}
	prepare();
	int o = 1; cin >> o;
	while(o --> 0) solve();
}