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
#define rep(i, n) fo(i, 0, n - 1)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define int long long
#define mxn 1'000'007

int n, h, w, a[8], b[8], m[11][11], used[8];

inline bool check(int r1, int c1, int r2, int c2){
	fo(i, r1, r2) fo(j, c1, c2) if(m[i][j]) return 0;
	return 1;
}

inline void bat(int r1, int c1, int r2, int c2){
	fo(i, r1, r2) fo(j, c1, c2) m[i][j] = 1;
}

inline void tat(int r1, int c1, int r2, int c2){
	fo(i, r1, r2) fo(j, c1, c2) m[i][j] = 0;
}

bool run(){
	fo(i, 1, h) fo(j, 1, w) if(m[i][j] == 0){
		fo(idx, 1, n) if(!used[idx] and i + a[idx] - 1 <= h and j + b[idx] - 1 <= w){
			if(check(i, j, i + a[idx] - 1, j + b[idx] - 1)){
				used[idx] = 1;
				bat(i, j, i + a[idx] - 1, j + b[idx] - 1);
				if(run()) return 1;
				used[idx] = 0;
				tat(i, j, i + a[idx] - 1, j + b[idx] - 1);
			}
		}
		fo(idx, 1, n) if(!used[idx] and i + b[idx] - 1 <= h and j + a[idx] - 1 <= w){
			if(check(i, j, i + b[idx] - 1, j + a[idx] - 1)){
				used[idx] = 1;
				bat(i, j, i + b[idx] - 1, j + a[idx] - 1);
				if(run()) return 1;
				used[idx] = 0;
				tat(i, j, i + b[idx] - 1, j + a[idx] - 1);
			}
		}
		return 0;
	}
	return 1;
}

inline void LonggVuz(){
	cin >> n >> h >> w;
	fo(i, 1, n) cin >> a[i] >> b[i];
	int tmp = 0;
	fo(i, 1, n) tmp += a[i] * b[i];
	if(tmp < h * w) ret("No");
	if(run()) ret("Yes");
	ret("No");
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "LonggVuz"
	if(fopen(name".inp", "r")){
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}