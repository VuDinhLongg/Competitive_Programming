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

struct nodetree{
    struct node{
        int u, v;
        node(int x = 0){
            u = x;
            v = -1;
        }
    };
    int n; vec<node> f; vec<int> lz;
    nodetree(int _n){
        n = _n; f.resize(n * 4 + 5); lz.resize(n * 4 + 5);
    }
    void range(int l, int r, int x){ range(1, 1, n, l, r, x); }
    void point(int i, int x){ point(1, 1, n, i, x); }
    node get(int l, int r){ return get(1, 1, n, l, r); }
    // Functions
    void push(int id, int l, int r){
        if(lz[id] < 0){
            int m = l + r >> 1;
            lz[id * 2] = lz[id * 2 + 1] = lz[id];
            f[id * 2] = node(m - l + 1);
            f[id * 2 + 1] = node(r - m);
            lz[id] = 0;
        }
        if(lz[id] > 0){
            lz[id * 2] = lz[id * 2 + 1] = lz[id];
            f[id * 2] = f[id * 2 + 1] = node(0);
            lz[id] = 0;
        }
    }
    void merge(node &a, node &b, node &c, int l = 0, int r = 0){
        a.u = max(b.u, c.u);
        a.v = max(min(b.u, c.u), max(b.v, c.v));
    }
    void build(int id, int l, int r){
        if(l == r){
            f[id] = node(0);
            return;
        }
        int m = (l + r) >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        merge(f[id], f[id * 2], f[id * 2 + 1]);
    }
    void point(int id, int l, int r, int i, int x){
        if(l == r){
            f[id] = node(x);
            return;
        }
        int m = (l + r) >> 1;
        if(i <= m) point(id * 2, l, m, i, x);
        else point(id * 2 + 1, m + 1, r, i, x);
        merge(f[id], f[id * 2], f[id * 2 + 1]);
    }
    void range(int id, int l, int r, int u, int v, int x){
        if(r < u or v < l) return;
        if(u <= l and r <= v){
            if(x){
                lz[id] = 1;
                f[id] = node(0);
            }else{
                lz[id] = -1;
                f[id] = node(r - l + 1);
            }
            return;
        }
        push(id, l, r);
        int m = (l + r) >> 1;
        range(id * 2, l, m, u, v, x);
        range(id * 2 + 1, m + 1, r, u, v, x);
        merge(f[id], f[id * 2], f[id * 2 + 1], m - l + 1, r - m);
    }
    node get(int id, int l, int r, int u, int v){
        if(r < u or v < l) return node(-1);
        if(u <= l and r <= v) return f[id];
        push(id, l, r);
        int m = (l + r) >> 1;
        node le = get(id * 2, l, m, u, v);
        node ri = get(id * 2 + 1, m + 1, r, u, v);
        if(le.u < 0) return ri;
        if(ri.u < 0) return le;
        node res;
        merge(res, le, ri);
        return res;
    }
};

void LonggVuz(){
    int n, m; cin >> n >> m;
    int a[n+5];
    nodetree s(n);
    fo(i, 1, n){
        cin >> a[i];
        s.point(i, a[i]);
    }
    while(m--){
        char c; cin >> c;
        if(c == 'Q'){
            int l, r; cin >> l >> r;
            auto [u, v] = s.get(l, r);
            cout << u + v, el;
        }else{
            int u, val; cin >> u >> val;
            s.point(u, val);
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
