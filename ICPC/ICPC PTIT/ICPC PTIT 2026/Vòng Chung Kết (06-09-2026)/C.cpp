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

bool p[mxn];
vector<int> v;

void prepare(){
	fo(i, 2, 1e6) p[i] = 1;
	fo(i, 2, 1e3) if(p[i]){
		for(int j = i * i; j <= 1e6; j += i) p[j] = 0;
	}
	fo(i, 2, 1e6) if(p[i]) v.push_back(i);
}

int calc(int n){
	int res = 0;
	for(int &i : v){
		if(i * i > n) break;
		int l = 1, r = 40;
		while(r - l > 1){
			int mid = l + r >> 1;
			int cur = 1, ok = 1;
			fo(t, 1, mid){
				if(cur * i > n){
					ok = 0; break;
				}
				cur *= i;
			}
			if(ok) l = mid;
			else r = mid;
		}
		res += l - 2 + 1;
	}
	return res;
}

inline void solve(){
    int l, r; cin >> l >> r;
    cout << calc(r) - calc(l - 1), el;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #define name "icpc"
    if(fopen(name".inp", "r")){
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    prepare();
    int o = 1; cin >> o;
    while(o --> 0) solve();
}