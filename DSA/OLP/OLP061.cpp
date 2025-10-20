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

string s, t;
int n, q, ten[mxn], base = 11;

struct node{
    int len, val;
    node(){};
    node(int _len, int _val){ len = _len; val = _val; }
};

struct nodetree{
    int n; vec<node> f; vec<int> lz;
    nodetree(int _n){
        n = _n; f.resize(n * 4 + 5); lz.resize(n * 4 + 5);
    }
    void build(){ build(1, 1, n); }
    void range(int l, int r, int x){ range(1, 1, n, l, r, x); }
    void point(int i, int x){ point(1, 1, n, i, x); }
    node get(int l, int r){ return get(1, 1, n, l, r); }
    // Functions
    node merge(node &b, node &c, int l, int r, int u, int v){
        node a;
        a.len = b.len + c.len;
        a.val = (b.val * ten[c.len] % mod + c.val) % mod;
        return a;
    }
    void push(int id, int l, int r){
        
    }
    void build(int id, int l, int r){
        if(l == r){
            return;
        }
        int m = (l + r) >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        // f[id] = merge(f[id * 2], f[id * 2 + 1], l, r, u, v);
    }
    void range(int id, int l, int r, int u, int v, int x){
        if(r < u or v < l) return;
        if(u <= l and r <= v){
            return;
        }
        push(id, l, r);
        int m = (l + r) >> 1;
        range(id * 2, l, m, u, v, x);
        range(id * 2 + 1, m + 1, r, u, v, x);
        // f[id] = merge(f[id * 2], f[id * 2 + 1], l, r, u, v);
    }
    void point(int id, int l, int r, int i, int x){
        if(l == r){
            f[id] = node(1, x);
            return;
        }
        int m = (l + r) >> 1;
        if(i <= m) point(id * 2, l, m, i, x);
        else point(id * 2 + 1, m + 1, r, i, x);
        f[id] = merge(f[id * 2], f[id * 2 + 1], l, r, 1, n);
    }
    node get(int id, int l, int r, int u, int v){
        if(r < u or v < l) return node(-oo, -oo);
        if(u <= l and r <= v) return f[id];
        push(id, l, r);
        int m = (l + r) >> 1;
        node le = get(id * 2, l, m, u, v);
        node ri = get(id * 2 + 1, m + 1, r, u, v);
        if(le.val == -oo) return ri;
        if(ri.val == -oo) return le;
        return merge(le, ri, l, r, u, v);
    }
};

inline void LonggVuz(){
    ten[0] = 1;
    fo(i, 1, 2e5) ten[i] = ten[i - 1] * base % mod;
    cin >> s >> q;
    t = s; reverse(all(t));
    n = len(s);
    s = " " + s;
    t = " " + t;
    nodetree segs(n), segt(n);
    fo(i, 1, n){
        segs.point(i, s[i] - '0' + 1);
        segt.point(i, t[i] - '0' + 1);
    }
    while(q--){
        char c; cin >> c;
        if(c == 'c'){
            int i; char x; cin >> i >> x;
            s[i] = x;
            segs.point(i, s[i] - '0' + 1);
            int j = n - i + 1;
            t[j] = x;
            segt.point(j, t[j] - '0' + 1);
        }else{
            int l, r; cin >> l >> r;
            node gets = segs.get(l, r);
            node gett = segt.get(n - r + 1, n - l + 1);
            if(gets.val == gett.val) cout << "YES\n";
            else cout << "NO\n";
        }
    }
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
