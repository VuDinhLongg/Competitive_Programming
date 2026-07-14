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
#define len(x) (int)(x).size()
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 2'000'007

int n, k;
bool nto[mxn];
vector<int> val;

int calc(int t1, int t2, int t3){
	--t1; --t2; --t3;
	if(!t1 or !t2 or !t3) return 0;
	fd(i, len(val) - 3, 0){
		int p1 = val[i];
		int p2 = val[i + 1];
		int p3 = val[i + 2];
		int res = 1, ok = 1;
		rep(_, t1){
			if(res > n / p1){
				ok = 0; break;
			}
			res *= p1;
		}
		rep(_, t2){
			if(res > n / p2){
				ok = 0; break;
			}
			res *= p2;
		}
		rep(_, t3){
			if(res > n / p3){
				ok = 0; break;
			}
			res *= p3;
		}
		if(ok) return res;
	}
	return 0;
}

inline void LonggVuz(){
	fo(i, 2, 2e6) nto[i] = 1;
	fo(i, 2, 2e3) if(nto[i]){
		for(int j=i*i; j<=2e6; j+=i) nto[j] = 0;
	}
	fo(i, 2, 2e6) if(nto[i]) val.push_back(i);

	cin >> n >> k;
	int res = 0;
	fo(t1, 2, k) fo(t2, 2, k) if(t1 * t2 <= k and k % (t1 * t2) == 0){
		int t3 = k / (t1 * t2);
		int ans = calc(t1, t2, t3);
		maxi(res, ans);
	}
	assert(res <= n);
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(false) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
