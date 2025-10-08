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

#define pii pair<int, int>
#define fi first
#define se second

int n, q, a[mxn];
pii seg[mxn * 4];

pii merge(pii x, pii y){
    if(x.fi < y.fi) return x;
    if(x.fi > y.fi) return y;
    return x.se < y.se ? x : y;
}

void upd(int id, int l, int r, int i, int x){
    if(l == r){
        seg[id] = {x, i};
        return;
    }
    int m = l + r >> 1;
    if(i <= m) upd(id * 2, l, m, i, x);
    else upd(id * 2 + 1, m + 1, r, i, x);
    seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

pii get(int id, int l, int r, int u, int v){
    if(r < u or v < l) return {oo, oo};
    if(u <= l and r <= v) return seg[id];
    int m = l + r >> 1;
    return merge(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

inline void LonggVuz(){
    cin >> n >> q;
    fo(i, 1, n){
        cin >> a[i];
        upd(1, 1, n, i, a[i]);
    }
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int i, x; cin >> i >> x;
            upd(1, 1, n, i, x);
        }else{
            int l, r; cin >> l >> r;
            pii res = get(1, 1, n, l, r);
            cout << res.se, el;
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
