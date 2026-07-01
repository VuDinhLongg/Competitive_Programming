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
#define mxn 200'007

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

struct node{
	char t;
	int s, u, v, id;
};

int n, q, ans[mxn];
vector<array<int, 3>> tv[mxn];

inline void LonggVuz(){
	cin >> n >> q;
	vector<node> vt;
	fo(i, 1, q){
		node x;
		x.id = i;
		cin >> x.t;
		if(x.t == 'A'){
			cin >> x.u >> x.v;
			vt.push_back(x);
		}
		if(x.t == '?'){
			cin >> x.u >> x.v;
			vt.push_back(x);
		}
		if(x.t == 'C'){
			vt.push_back(x);
		}
		if(x.t == 'Q'){
			cin >> x.s >> x.u >> x.v;
			tv[x.s].push_back({x.u, x.v, i});
			vt.push_back(x);
		}
	}
	DSU dsu(n);
	int idx = 0;
	for(node &x : vt){
		if(x.t == 'A'){
			dsu.merge(x.u, x.v);
		}
		if(x.t == '?'){
			ans[x.id] = dsu.same(x.u, x.v);
		}
		if(x.t == 'C'){
			++idx;
			for(auto &[u, v, id] : tv[idx]){
				ans[id] = dsu.same(u, v);
			}
		}
	}
	fo(i, 1, q) if(vt[i - 1].t == '?' or vt[i - 1].t == 'Q') cout << (ans[i] ? 'Y' : 'N');
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(false) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
