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

struct DSU{
    vector<int> boss, sz;
    DSU(int n){
        boss.resize(n + 5);
        iota(all(boss), 0);
        sz.assign(n + 5, 1);
    }
    int find(int u){
        while(u ^ boss[u]) u = boss[u] = boss[boss[u]];
    	return u;
    }
    bool merge(int u, int v){
        u = find(u); v = find(v);
        if(u == v) return false;
        if(sz[u] < sz[v]) swap(u, v);
        boss[v] = u;
        sz[u] += sz[v];
        return true;
    }
    int size(int u){ return sz[find(u)]; }
    bool same(int u, int v){ return find(u) == find(v); }
};

int n, m, f[mxn], mod = 1e9 + 7;

inline void LonggVuz(){
	f[0] = 1;
	fo(i, 1, 1e5) f[i] = f[i - 1] * i % mod;
	cin >> n >> m;
	DSU dsu(n);
	rep(i, m){
		int u, v; cin >> u >> v;
		++u; ++v;
		dsu.merge(u, v);
	}
	int res = 0;
	fo(u, 1, n) if(u == dsu.find(u) and dsu.size(u) > 2){
		dbg(u, dsu.size(u));
		res += f[dsu.size(u)];
		res %= mod;
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(false) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
