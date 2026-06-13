/*----------------------
   Author : @LonggVuz
----------------------*/
#include <bits/stdc++.h>
using namespace std;

#ifdef ChatGPT
#include <ChatGPT.h>
#else
#define debug(...) 1608
#define print(...) 2005
#endif

#define el cout << '\n'
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define out(x) return void(cout << (x))
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

struct node{
    int max, sum;
    node(){}
    node(int _max, int _sum){
        max = _max; sum = _sum;
    }
};

int n, q, a[mxn];
node seg[mxn * 4];

node merge(node &l, node &r){
    node res;
    res.max = max(l.max, r.max);
    res.sum = l.sum + r.sum;
    return res;
}

void upd(int id, int l, int r, int i, int x){
    if(l == r){
        seg[id] = node(x, x);
        return;
    }
    int m = l + r >> 1;
    if(i <= m) upd(id * 2, l, m, i, x);
    else upd(id * 2 + 1, m + 1, r, i, x);
    seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

node get(int id, int l, int r, int u, int v){
    if(r < u or v < l) return node(-oo, 0);
    if(u <= l and r <= v) return seg[id];
    int m = l + r >> 1;
    node le = get(id * 2, l, m, u, v);
    node ri = get(id * 2 + 1, m + 1, r, u, v);
    return merge(le, ri);
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
            a[i] = x;
        }else{
            int l, r; cin >> l >> r;
            node res = get(1, 1, n, l, r);
            if(res.max < res.sum - res.max) cout << 1, el;
            else cout << 0, el;
        }
    }
}

signed main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    
    signed o_o = 1; if(false) cin >> o_o;
    fo(_, 1, o_o) print(_), LonggVuz();
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
