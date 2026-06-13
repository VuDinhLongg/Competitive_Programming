// LonggVuz
#include<bits/stdc++.h>
using namespace std;
#define el cout << '\n'
#define inc(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define dec(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int32_t i=a; i<=b; i++)
#define fd(i, a, b) for(int32_t i=a; i>=b; i--)
#define out(x) return void(cout << (x));
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pb push_back
#define po pop_back
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 8;
const int mxn = 1e6 + 9;

struct dsu{
    int n; vec<int> p, sz;
    dsu(int _n){
        n = _n; p.resize(n + 5); sz.resize(n + 5);
        fo(i, 1, n) p[i] = i, sz[i] = 1;
    }
    int get(int u){
        if(u == p[u]) return u;
        return p[u] = get(p[u]);
    }
    void uni(int u, int v){
        u = get(u); v = get(v);
        if(u == v) return;
        if(u > v) swap(u, v);
        p[v] = u;
        sz[u] += sz[v];
    }
};

void LonggVuz(){
    int n, m; cin >> n >> m;
    dsu d(n);
    fo(i, 1, m){
        int x, y; cin >> x >> y;
        d.uni(x, y);
    }
    int res = 0;
    fo(i, 1, n) res = max(res, d.sz[d.get(i)]);
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; //cin >> orz;
    while(orz--){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
