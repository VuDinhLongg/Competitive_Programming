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

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 500'007

int n, nxt[mxn], f[mxn];
string s;
vector<int> pos;

int calc(int len){
	int ans = 0;
	char c = '0';
	int need = len;
	int i = 0;
	while(i <= n){
		if(c == '0'){
			int idx = f[i];
			if(idx + need - 1 >= len(pos)) break;
			i = pos[idx + need - 1];
			++ans;
			c = '1';
			need = 1;
		}else{
			i = nxt[i];
			c = '0';
			need = len;
		}
	}
	return ans;
}

inline void LonggVuz(){
	cin >> n >> s;
	s = " " + s;
	fo(i, 1, n){
		f[i] = f[i - 1];
		if(s[i] == '0'){
			++f[i];
			pos.push_back(i);
		}
	}
	int p = n + 1;
	fd(i, n, 1){
		nxt[i] = p;
		if(s[i] == '1') p = i;
	}
	int res = n - f[n];
	fd(len, f[n] / 2, 1){
		int ans = calc(len);
		if(ans >= 2){
			maxi(res, ans * len + (ans - 1));
		}
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	#ifdef LOCAL
	freopen("LonggVuz.inp", "r", stdin); freopen("1.out", "w", stdout);
	#endif
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
