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
    int x, y, z; // chia 3 du 0(x), 1(y), 2(z);
    node(){}
    node(int _x, int _y, int _z){
        x = _x; y = _y; z = _z;
    }
};

int n, q, lz[mxn * 4];
node seg[mxn * 4];

node merge(node &a, node &b){
    node res;
    res.x = a.x + b.x;
    res.y = a.y + b.y;
    res.z = a.z + b.z;
    return res;
}

void build(int id, int l, int r){
    if(l == r){
        seg[id] = node(1, 0, 0);
        return;
    }
    int m = l + r >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

void push(int id, int l, int r){
    if(lz[id] == 0) return;
    if(lz[id] == 1){
        int tmp = seg[id * 2].z;
        seg[id * 2].z = seg[id * 2].y;
        seg[id * 2].y = seg[id * 2].x;
        seg[id * 2].x = tmp;
        lz[id * 2] = (lz[id * 2] + 1) % 3;
        tmp = seg[id * 2 + 1].z;
        seg[id * 2 + 1].z = seg[id * 2 + 1].y;
        seg[id * 2 + 1].y = seg[id * 2 + 1].x;
        seg[id * 2 + 1].x = tmp;
        lz[id * 2 + 1] = (lz[id * 2 + 1] + 1) % 3;
        lz[id] = 0;
    }
    if(lz[id] == 2){
        int tmp = seg[id * 2].z;
        seg[id * 2].z = seg[id * 2].x;
        seg[id * 2].x = seg[id * 2].y;
        seg[id * 2].y = tmp;
        lz[id * 2] = (lz[id * 2] + 2) % 3;
        tmp = seg[id * 2 + 1].z;
        seg[id * 2 + 1].z = seg[id * 2 + 1].x;
        seg[id * 2 + 1].x = seg[id * 2 + 1].y;
        seg[id * 2 + 1].y = tmp;
        lz[id * 2 + 1] = (lz[id * 2 + 1] + 2) % 3;
        lz[id] = 0;
    }
}

void upd(int id, int l, int r, int u, int v){
    if(r < u or v < l) return;
    if(u <= l and r <= v){
        int tmp = seg[id].z;
        seg[id].z = seg[id].y;
        seg[id].y = seg[id].x;
        seg[id].x = tmp;
        lz[id] = (lz[id] + 1) % 3;
        return;
    }
    push(id, l, r);
    int m = l + r >> 1;
    upd(id * 2, l, m, u, v);
    upd(id * 2 + 1, m + 1, r, u, v);
    seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

node get(int id, int l, int r, int u, int v){
    if(r < u or v < l) return node(0, 0, 0);
    if(u <= l and r <= v) return seg[id];
    push(id, l, r);
    int m = l + r >> 1;
    node le = get(id * 2, l, m, u, v);
    node ri = get(id * 2 + 1, m + 1, r, u, v);
    return merge(le, ri);
}

inline void LonggVuz(){
    cin >> n >> q;
    build(1, 1, n);
    while(q--){
        int t, l, r; cin >> t >> l >> r;
        if(t == 0){
            upd(1, 1, n, l, r);
        }else{
            node res = get(1, 1, n, l, r);
            cout << res.x, el;
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
