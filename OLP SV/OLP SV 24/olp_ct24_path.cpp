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
#define mxn 1007

const int mod = 1e9 + 7;

struct mint{
    int x; mint(const int &o = 0){ x = o % mod; if(x < 0) x += mod; }
    mint &operator = (const mint &o){ x = o.x; return *this; }
    mint &operator += (const mint &o){ x += o.x; if(x >= mod) x -= mod; return *this; }
    mint &operator -= (const mint &o){ x -= o.x; if(x < 0) x += mod; return *this; }
    mint &operator *= (const mint &o){ x = x * o.x % mod; return *this; }
    mint &operator /= (const mint &o){ return (*this) *= Pow(o, mod - 2); }
    mint operator + (const mint &o) const { return mint(*this) += o; }
    mint operator - (const mint &o) const { return mint(*this) -= o; }
    mint operator * (const mint &o) const { return mint(*this) *= o; }
    mint operator / (const mint &o) const { return mint(*this) /= o; }
    bool operator == (const mint &o) const { return x == o.x; }
    bool operator != (const mint &o) const { return x != o.x; }
    bool operator > (const mint &o) const { return x > o.x; }
    bool operator < (const mint &o) const { return x < o.x; }
    friend ostream &operator << (ostream &out, const mint &o){ return out << o.x; }
    friend mint Pow(mint a, int b){
        mint r = 1;
        while(b){ if(b & 1) r *= a; a *= a; b >>= 1; }
        return r;
    }
};

struct Combinatoric{
	int n;
	vector<int> fact, invfact;
	Combinatoric(int _n){
		n = _n;
		fact.resize(n + 5);
		invfact.resize(n + 5);
		fact[0] = 1;
		for(int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % mod;
		invfact[n] = inverse(fact[n]);
		for(int i = n; i >= 1; --i) invfact[i - 1] = invfact[i] * i % mod;
	}
	int Pow(int a, int n){
		int r = 1; a %= mod;
		for(; n; n >>= 1, a = a * a % mod) if(n & 1) r = r * a % mod;
		return r;
	}
	int inverse(int a){ return Pow(a, mod - 2); }
	int C(int n, int k){
		if(n < 0 or k < 0 or n < k) return 0;
		return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
	}
	int Euler(int n, int k){ return C(n + k - 1, n); }
} Calc(1e6) ;

int n, m, k;
bool bad[mxn][mxn];
mint dp[mxn][mxn];

mint get(int x, int y){
	return Calc.C(n - x + m - y, n - x);
}

inline void LonggVuz(){
    cin >> n >> m >> k;
    rep(i, k){
    	int x, y; cin >> x >> y;
    	bad[x][y] = 1;
    }
    dp[1][1] = 1;
    int nn = min(n, (int)1000);
    int mm = min(m, (int)1000);
    fo(i, 2, nn) if(!bad[i][1]) dp[i][1] = dp[i - 1][1];
    fo(i, 2, mm) if(!bad[1][i]) dp[1][i] = dp[1][i - 1];
    fo(i, 2, nn) fo(j, 2, mm) if(!bad[i][j]){
    	dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
    mint res = 0;
    fo(i, 1, nn - 1){
    	mint ans = get(i, mm + 1) * dp[i][mm];
    	res += ans;
    }
    fo(i, 1, mm - 1){
    	mint ans = get(nn + 1, i) * dp[nn][i];
    	res += ans;
    }
    res += get(nn, mm) * dp[nn][mm];
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
