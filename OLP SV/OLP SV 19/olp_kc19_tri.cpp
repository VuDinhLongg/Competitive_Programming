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
#define mxn 100'007

int n, k, d[mxn];

namespace sub1{
	bool check(){
		return k == n and n == 3;
	}
	void solve(){
		sort(d+1, d+n+1);
		if(d[1] + d[2] > d[3]) cout << 1;
		else cout << 0;
	}
}

namespace sub2{
	bool check(){
		return k == n and n == 4;
	}
	void solve(){
		sort(d+1, d+n+1);
		int res = 0;
		fo(i, 2, 4){
			int a = d[1] + d[i];
			int b = 0;
			int c = 0;
			if(i == 2) b = d[3], c = d[4];
			if(i == 3) b = d[2], c = d[4];
			if(i == 4) b = d[2], c = d[3];
			if(a + b > c and a + c > b and b + c > a){
				res = 1;
				break;
			}
		}
		cout << res;
	}
}

namespace sub3{
	bool check(){
		return k == n and n <= 10;
	}
	int g[16], res;
	void run(int idx){
		fo(i, 1, 3){
			g[idx] = i;
			if(idx == n){
				int a = 0, b = 0, c = 0;
				fo(j, 1, n){
					if(g[j] == 1) a += d[j];
					if(g[j] == 2) b += d[j];
					if(g[j] == 3) c += d[j];
				}
				if(a + b > c and a + c > b and b + c > a) res = 1;
			}else run(idx + 1);
			g[idx] = 0;
		}
	}
	void solve(){
		run(1);
		cout << res;
	}
}

namespace sub4{
	bool check(){
		return k <= n and n <= 1000;
	}
	bool calc(int l, int r){
		int len = r - l + 1;
		if(len < 3) return 0;
		int sum = 0, mx = 0;
		fo(i, l, r){
			sum += d[i];
			maxi(mx, d[i]);
		}
		return mx < sum - mx;
	}
	void solve(){
		int res = 0;
		fo(i, 1, n - k + 1) res += calc(i, i + k - 1);
		cout << res;
	}
}

namespace sub5{
	bool check(){
		return 1;
	}
	void solve(){
		int res = 0, sum = 0;
		multiset<int> ms;
		fo(i, 1, k){
			sum += d[i];
			ms.insert(d[i]);
		}
		if(*ms.rbegin() < sum - *ms.rbegin()) ++res;
		fo(i, k + 1, n){
			ms.erase(ms.find(d[i - k]));
			sum -= d[i - k];
			ms.insert(d[i]);
			sum += d[i];
			if(*ms.rbegin() < sum - *ms.rbegin()) ++res;
		}
		cout << res;
	}
}

inline void LonggVuz(){
    cin >> n >> k;
    fo(i, 1, n) cin >> d[i];
    if(sub1::check()) sub1::solve();
    else if(sub2::check()) sub2::solve();
    else if(sub3::check()) sub3::solve();
    else if(sub4::check()) sub4::solve();
    else sub5::solve();
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
