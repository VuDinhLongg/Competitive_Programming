#include <bits/stdc++.h>
using namespace std;

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define rep(i, n) fo(i, 0, n - 1)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define int long long
#define mxn 1'000'007
#define mask(n) (1ll << (n))
#define bit(n, i) ((n) >> (i) & 1)
#define one(n) __builtin_popcountll(n)
#define clz(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctzll(n)

int n, z[1005], dp[1005][mask(3)][mask(3)], cnt[1005][mask(3)][mask(3)];

bool check1(int i, int m1){
	if(z[i]) return bit(m1, z[i] - 1) == 0;
	return 1; 
}

bool check2(int m1, int m2){
	if(bit(m1, 0) and bit(m2, 2)) return 0;
	if(bit(m1, 2) and bit(m2, 0)) return 0;
	return 1;
}

bool check3(int m1, int m2){
	if(bit(m1, 0) and bit(m2, 1)) return 0;
	if(bit(m1, 1) and bit(m2, 0)) return 0;
	if(bit(m1, 1) and bit(m2, 2)) return 0;
	if(bit(m1, 2) and bit(m2, 1)) return 0;
	return 1;
}

inline void solve(){
    cin >> n;
    assert(n <= 100);
    fo(i, 1, n) cin >> z[i];
    if(n == 1){
		if(z[1]) cout << 2 << ' ' << 1;
		else cout << 3 << ' ' << 1;
		return;
    }
    int full = mask(3) - 1;
    fo(m1, 0, full) fo(m2, 0, full) if(check1(1, m1) and check1(2, m2) and check2(m1, m2)){
		dp[2][m1][m2] = one(m1) + one(m2);
		cnt[2][m1][m2] = 1;
    }
    fo(i, 3, n) fo(m2, 0, full) fo(m3, 0, full) fo(m1, 0, full){
		if(check1(i - 2, m1) and check1(i - 1, m2) and check1(i, m3) and check2(m1, m2) and check2(m2, m3) and check3(m1, m3)){
			if(maxi(dp[i][m2][m3], dp[i - 1][m1][m2] + one(m3))){
				cnt[i][m2][m3] = cnt[i - 1][m1][m2];
			}else if(dp[i][m2][m3] == dp[i - 1][m1][m2] + one(m3)){
				cnt[i][m2][m3] += cnt[i - 1][m1][m2];
			}
		}
    }
    int res = 0, ans = 0;
    fo(m2, 0, full) fo(m3, 0, full) if(check1(n - 1, m2) and check1(n, m3) and check2(m2, m3)){
		if(maxi(res, dp[n][m2][m3])){
			ans = cnt[n][m2][m3];
		}else if(res == dp[n][m2][m3]){
			ans += cnt[n][m2][m3];
		}
    }
    cout << res << ' ' << ans;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #define name "icpc"
    if(fopen(name".inp", "r")){
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    
    int o = 1; ///cin >> o;
    while(o --> 0) solve();
}