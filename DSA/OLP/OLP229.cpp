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

struct segtree{
    int n; vec<int> f, lz;
    segtree(int _n){
        n = _n; f.resize(n * 4 + 5); lz.resize(n * 4 + 5);
    }
    int sum(int a, int b){ return a + b; }
    int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }
    void range(int l, int r, int x){ range(1, 1, n, l, r, x); }
    void point(int i, int x){ point(1, 1, n, i, x); }
    int get(int l, int r){ return get(1, 1, n, l, r); }
    // Functions
    void push(int id, int l, int r){
        lz[id * 2] += lz[id];
        lz[id * 2 + 1] += lz[id];
        f[id * 2] += lz[id];
        f[id * 2 + 1] += lz[id];
        lz[id] = 0;
    }
    void range(int id, int l, int r, int u, int v, int x){
        if(r < u or v < l) return;
        if(u <= l and r <= v){
            lz[id] += x;
            f[id] += x;
            return;
        }
        if(lz[id]) push(id, l, r);
        int m = (l + r) >> 1;
        range(id * 2, l, m, u, v, x);
        range(id * 2 + 1, m + 1, r, u, v, x);
        f[id] = max(f[id * 2], f[id * 2 + 1]);
    }
    void point(int id, int l, int r, int i, int x){
        if(l == r){
            f[id] += x;
            return;
        }
        int m = (l + r) >> 1;
        if(i <= m) point(id * 2, l, m, i, x);
        else point(id * 2 + 1, m + 1, r, i, x);
        f[id] = min(f[id * 2], f[id * 2 + 1]);
    }
    int get(int id, int l, int r, int u, int v){
        if(r < u or v < l) return oo;
        if(u <= l and r <= v) return f[id];
        if(lz[id]) push(id, l, r);
        int m = (l + r) >> 1;
        int le = get(id * 2, l, m, u, v);
        int ri = get(id * 2 + 1, m + 1, r, u, v);
        return min(le, ri);
    }
};

void LonggVuz(){
    int n, q; cin >> n >> q;
    int a[n+5];
    segtree s(n);
    map<int, set<int>> pos;
    fo(i, 1, n){
        cin >> a[i];
        pos[a[i]].insert(i);
        s.point(i, a[i]);
    }
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int u, val; cin >> u >> val;
            s.point(u, -a[u] + val);
            pos[a[u]].erase(u);
            a[u] = val;
            pos[a[u]].insert(u);
        }else{
            int l, r; cin >> l >> r;
            int g = s.get(l, r);
            auto it = pos[g].lower_bound(l);
            cout << *it, el;
        }
    }
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
