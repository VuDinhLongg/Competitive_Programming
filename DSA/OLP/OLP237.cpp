// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LonggVuz
#include <LonggVuz.h>
#else
#define debug(...)
#endif

#define el cout << '\n'
#define inc(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define dec(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int32_t i=a; i<=b; i++)
#define fd(i, a, b) for(int32_t i=a; i>=b; i--)
#define out(x) return void(cout << (x))
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define dub double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 2e5 + 7;

struct fenwick{
    int n; vec<int> f, g;
    fenwick(int _n){
        n = _n; f.resize(n + 5); g.resize(n + 5);
    }
    void upd1(int x, int v){
        for(; x >= 1 ; x -= x & -x) g[x] += v;
    }
    void updn(int x, int v){
        for(; x <= n ; x += x & -x) f[x] += v;
    }
    int get1(int x){
        int s = 0;
        for(; x >= 1 ; x -= x & -x) s += f[x];
        return s;
    }
    int getn(int x){
        int s = 0;
        for(; x <= n ; x += x & -x) s += g[x];
        return s;
    }
};

int n, m, k;
vec<int> h[mxn], c[mxn];

inline void LonggVuz(){
    cin >> n >> m >> k;
    fo(i, 1, k){
        int u, v; cin >> u >> v;
        h[u].pub(v);
        c[v].pub(u);
    }
    fo(i, 1, 2e5){
        sort(all(h[i]));
        sort(all(c[i]));
    }
    int res = 0;
    fo(i, 1, m){
        if(!h[1].empty() and i == h[1][0]) break;
        if(!c[i].empty()){
            res += c[i][0] - 1;
        }else res += n;
    }
    debug(res);
    fenwick f(m);
    fo(i, 1, n){
        if(!c[1].empty() and i == c[1][0]) break;
        int lim = m;
        if(!h[i].empty()) lim = h[i][0] - 1;
        res += f.get1(lim);
        if(i == 1 and !h[1].empty()){
            fo(j, h[1][0], m) f.updn(j, 1);
        }
        for(int &j : h[i]){
            if(f.get1(j) == f.get1(j - 1)) f.updn(j, 1);
        }
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; if(false) cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
