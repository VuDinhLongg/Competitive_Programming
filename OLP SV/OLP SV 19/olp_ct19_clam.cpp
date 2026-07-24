/*======================
   Author : @LonggVuz (AC Sub1 = 40%)
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
#define mxn 1'000'007

int n, m, q, red, a[1005][1005];

namespace sub1{
	bool check(){
		return n <= 400 and m <= 400;
	}
	void solve(){
		while(q--){
			int t; cin >> t;
			if(t == 1){
				int s, c1, r1, c2, r2; cin >> s >> c1 >> r1 >> c2 >> r2;
				int res = 0, ok = 1;
				fo(i, r1, r2){
					if((i - r1 + 1) & 1){
						fo(j, c1, c2){
							if(a[i][j] >= red){
								int add = min(a[i][j] - red, s - res);
								res += add;
								a[i][j] -= add;
							}else{
								ok = 0;
							}
						}
					}else{
						fd(j, c2, c1){
							if(a[i][j] >= red){
								int add = min(a[i][j] - red, s - res);
								res += add;
								a[i][j] -= add;
							}else{
								ok = 0;
							}
						}
					}
				}
				cout << (ok ? res : 0), el;
			}else{
				cin >> red;
			}
		}
	}
}

namespace sub2{
	bool check(){
		return 1;
	}
	void solve(){
		
	}
}

inline void LonggVuz(){
	cin >> n >> m;
	fo(i, 1, n) fo(j, 1, m){
		cin >> a[i][j];
	}
	cin >> q >> red;
	if(sub1::check()) sub1::solve();
	else sub2::solve();
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
