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
#define pub push_back
#define pob pop_back
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

struct canh{
    int u, v, w;
};

struct dsu{
    vec<int> p, s; // parent, size
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

int n, m;
vec<canh> ve;

void LonggVuz(){
    cin >> n >> m;
    int res = 0;
    fo(i, 1, m){
        int u, v, w; cin >> u >> v >> w;
        ve.pub({u, v, w});
        res += w;
    }
    sort(all(ve), [&](canh x, canh y){
        return x.w < y.w;
    });
    int cnt = 0;
    dsu d(n);
    for(auto &[u, v, w] : ve){
        if(w >= 0 and cnt >= n - 1) break;
        if(w < 0) res -= w;
        if(d.uni(u, v)){
            ++cnt;
            if(w >= 0) res -= w;
        }
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; //cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
