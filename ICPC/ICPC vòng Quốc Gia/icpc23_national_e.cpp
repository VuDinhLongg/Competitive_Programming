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
#define mxn 1'000'007

int h[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

int C(int n, int k){
	int res = 1;
	fo(i, n - k + 1, n) res = res * i / (i - n + k);
	return res;
}

inline void LonggVuz(){
	int n, a, b; cin >> n >> a >> b;
	if(a > b) swap(a, b);
	if(a < n){
		if(b < n){
			out(0);
		}else if(b == n){
			if(a <= n - 2){
				int res = C(a + b - 1, a);
				out(res);
			}else{
				out(0);
			}
		}else{
			if(a == n - 1 and b == n + 1){
				int res = C(n - 1 + n - 1, n - 1) * h[b - n - 1];
				out(res);
			}else{
				out(0);
			}
		}
	}else if(a == n){
		if(b == n){
			out(0);
		}else{
			if(a + 2 == b){
				int res = C(n - 1 + n - 1, n - 1) * h[b - n - 1];
				out(res);
			}else{
				out(0);
			}
		}
	}else{
		if(b - a == 2){
			int res = C(n - 1 + n - 1, n - 1) * h[b - n - 1];
			out(res);
		}else{
			out(0);
		}
	}
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(1) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
