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
#define mxn 200'007

const int mod = 1e9 + 7;

int n, m, d[mxn], c[mxn];
vector<int> g[mxn];

inline void LonggVuz(){
	cin >> n >> m;
	fo(i, 1, m){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	fo(u, 2, n) d[u] = 1e18;
	queue<int> q;
	q.push(1);
	c[1] = 1;
	while(len(q)){
		int u = q.front(); q.pop();
		for(int &v : g[u]){
			if(mini(d[v], d[u] + 1)){
				c[v] = c[u];
				q.push(v);
			}else if(d[v] == d[u] + 1){
				c[v] = (c[v] + c[u]) % mod;
			}
		}
	}
	cout << c[n];
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}