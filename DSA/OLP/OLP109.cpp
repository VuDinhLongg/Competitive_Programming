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
const int mxn = 1e5 + 7;

struct node{
    int x, y, z, lz;
    node(){ lz = 0; }
    node(int _x, int _y, int _z, int _lz){
        x = _x; y = _y; z = _z; lz = _lz;
    }
};

int n, q, a[mxn];
string s;
node seg[mxn * 4];

node merge(node &a, node &b){
    node res;
    res.x = a.x + b.x;
    res.y = a.y + b.y;
    res.z = a.z + b.z;
    res.lz = 0;
    return res;
}

void build(int id, int l, int r){
    if(l == r){
        if(a[l] == 0) seg[id] = node(1, 0, 0, 0);
        else if(a[l] == 1) seg[id] = node(0, 1, 0, 0);
        else seg[id] = node(0, 0, 1, 0);
        return;
    }
    int m = l + r >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

void edit(node &a, int d){
    if(d == 1){
        int t = a.z;
        a.z = a.y;
        a.y = a.x;
        a.x = t;
        a.lz = (a.lz + d) % 3;
    }else if(d == 2){
        int t = a.z;
        a.z = a.x;
        a.x = a.y;
        a.y = t;
        a.lz = (a.lz + d) % 3;
    }
}

void push(int id){
    if(seg[id].lz == 0) return;
    edit(seg[id * 2], seg[id].lz);
    edit(seg[id * 2 + 1], seg[id].lz);
    seg[id].lz = 0;
}

void upd(int id, int l, int r, int u, int v, int d){
    if(r < u or v < l) return;
    if(u <= l and r <= v){
        edit(seg[id], d);
        return;
    }
    push(id);
    int m = l + r >> 1;
    upd(id * 2, l, m, u, v, d);
    upd(id * 2 + 1, m + 1, r, u, v, d);
    seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

node get(int id, int l, int r, int u, int v){
    if(r < u or v < l) return node(oo, oo, oo, oo);
    if(u <= l and r <= v) return seg[id];
    push(id);
    int m = l + r >> 1;
    node le = get(id * 2, l, m, u, v);
    node ri = get(id * 2 + 1, m + 1, r, u, v);
    if(le.x == oo) return ri;
    if(ri.x == oo) return le;
    return merge(le, ri);
}

int cal(int x){
    return x * (x - 1) / 2;
}

inline void LonggVuz(){
    cin >> n >> q >> s;
    s = " " + s;
    fo(i, 1, n) a[i] = (a[i - 1] + s[i] - '0') % 3;
    build(1, 0, n);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int i; char c; cin >> i >> c;
            int d = c - s[i];
            d = (d % 3 + 3) % 3;
            upd(1, 0, n, i, n, d);
            s[i] = c;
        }else{
            int l, r; cin >> l >> r;
            node g = get(1, 0, n, l - 1, r);
            debug(l, r, g.x, g.y, g.z);
            int res = cal(g.x) + cal(g.y) + cal(g.z);
            cout << res, el;
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
