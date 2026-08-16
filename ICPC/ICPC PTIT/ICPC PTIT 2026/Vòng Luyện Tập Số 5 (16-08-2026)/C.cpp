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
#define mxn 1'000'007

struct node{
	int x, y;
};

int n, d, vis[2005];
node a[2005];
vector<int> g[2005];

int dist(int x, int y, int z, int t){
	return (x - z) * (x - z) + (y - t) * (y - t);
}

void dfs(int u){
	vis[u] = 1;
	for(int &v : g[u]) if(!vis[v]) dfs(v);
}

inline void LonggVuz(){
	cin >> n >> d;
	fo(i, 1, n) cin >> a[i].x >> a[i].y;
	fo(i, 1, n) fo(j, i + 1, n) if(dist(a[i].x, a[i].y, a[j].x, a[j].y) <= d * d){
		g[i].push_back(j);
		g[j].push_back(i);
	}
	dfs(1);
	fo(i, 1, n) cout << (vis[i] ? "Yes\n" : "No\n");
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}