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

int n, q, a[mxn], seg[mxn * 4], lz[2][mxn * 4];

void add(int &x, const int &y){
    x = (x + y + mod * 5) % mod;
}

int cal(int l, int r, int x){
    int sum = (r + l) * (r - l + 1) / 2;
    return x * sum % mod;
}

void push(int id, int l, int r){
    int m = l + r >> 1;
    if(lz[0][id]){
        add(seg[id * 2], lz[0][id] * (m - l + 1));
        add(lz[0][id * 2], lz[0][id]);
        add(seg[id * 2 + 1], lz[0][id] * (r - m));
        add(lz[0][id * 2 + 1], lz[0][id]);
        lz[0][id] = 0;
    }
    if(lz[1][id]){
        add(seg[id * 2], cal(1, m - l + 1, lz[1][id]));
        add(lz[1][id * 2], lz[1][id]);
        add(seg[id * 2 + 1], cal(1, r - m, lz[1][id]));
        add(lz[1][id * 2 + 1], lz[1][id]);
        add(seg[id * 2 + 1], lz[1][id] * (m + 1 - l) * (r - m));
        add(lz[0][id * 2 + 1], lz[1][id] * (m + 1 - l));
        lz[1][id] = 0;
    }
}

void upd(int id, int l, int r, int u, int v, int x){
    if(r < u or v < l) return;
    if(u <= l and r <= v){
        add(seg[id], cal(1, r - l + 1, x) + x * (l - u) * (r - l + 1));
        add(lz[0][id], x * (l - u) % mod);
        add(lz[1][id], x);
        return;
    }
    push(id, l, r);
    int m = l + r >> 1;
    upd(id * 2, l, m, u, v, x);
    upd(id * 2 + 1, m + 1, r, u, v, x);
    seg[id] = seg[id * 2];
    add(seg[id], seg[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v){
    if(r < u or v < l) return 0;
    if(u <= l and r <= v) return seg[id];
    push(id, l, r);
    int m = l + r >> 1;
    int le = get(id * 2, l, m, u, v);
    int ri = get(id * 2 + 1, m + 1, r, u, v);
    add(le, ri);
    return le;
}

inline void LonggVuz(){
    cin >> n >> q;
    fo(i, 1, n) cin >> a[i];
    fo(i, 1, n) upd(1, 1, n, i, n, a[i]);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x, val; cin >> x >> val;
            upd(1, 1, n, x, n, val - a[x]);
            a[x] = val;
        }else{
            int x; cin >> x;
            cout << get(1, 1, n, 1, x), el;
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
