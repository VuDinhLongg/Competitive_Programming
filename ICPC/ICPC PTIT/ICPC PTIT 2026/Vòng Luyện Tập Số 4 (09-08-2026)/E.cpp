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

int n, child[26][mxn], e[mxn], now, ans[mxn], d[mxn], dad[20][mxn];
string s[mxn];

void add(int i){
	int u = 0;
	for(char &c : s[i]){
		int k = c - 'a';
		if(child[k][u] == 0) child[k][u] = ++now;
		u = child[k][u];
	}
	++e[u];
	ans[i] = u;
}

void dfs(int u){
	fo(k, 0, 25){
		int v = child[k][u]; if(v){
			d[v] = d[u] + 1;
			dad[0][v] = u;
			fo(k, 1, 19) dad[k][v] = dad[k - 1][dad[k - 1][v]];
			dfs(v);
			e[u] += e[v];
		}
	}
}

inline void LonggVuz(){
	cin >> n;
	fo(i, 1, n){
		cin >> s[i];
		add(i);
	}
	dfs(0);
	fo(i, 1, n){
		int u = ans[i];
		if(e[u] == 1){
			fd(i, 19, 0) if(e[dad[i][u]] == 1) u = dad[i][u];
			u = dad[0][u];
		}
		cout << d[u], el;
	}
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}