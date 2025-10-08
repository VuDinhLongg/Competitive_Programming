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

const int mod = 998244353;
const int oo = 1e18 + 7;
const int mxn = 2e5 + 7;

struct dsu{
    vec<int> p, s;
    dsu(int n){
        p.resize(n + 5); iota(all(p), 0); s.resize(n + 5, 1);
    }
    int get(int u){
        return (u == p[u]) ? (u) : (p[u] = get(p[u]));
    }
    bool uni(int u, int v){
        u = get(u); v = get(v);
        if(u == v) return 0;
        if(u > v) swap(u, v);
        p[v] = u; s[u] += s[v];
        return 1;
    }
    int sz(int u){ return s[get(u)]; }
    bool same(int u, int v){ return get(u) == get(v); }
};

int n, p[mxn], q[mxn], lucas[mxn];

inline void LonggVuz(){
    lucas[0] = 2;
    lucas[1] = 1;
    fo(i, 2, 2e5) lucas[i] = (lucas[i - 1] + lucas[i - 2]) % mod;
    cin >> n;
    fo(i, 1, n) cin >> p[i];
    fo(i, 1, n) cin >> q[i];
    dsu d(n);
    fo(i, 1, n){
        d.uni(p[i], q[i]);
    }
    int res = 1;
    fo(i, 1, n) if(i == d.get(i)){
        res = (res * lucas[d.sz(i)]) % mod;
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
