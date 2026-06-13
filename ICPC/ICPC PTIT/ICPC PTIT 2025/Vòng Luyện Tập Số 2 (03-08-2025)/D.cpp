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
#define pb push_back
#define po pop_back

const int mod = 1e9 + 7;
const int oo = 1e8 + 8;
const int mxn = 5e5 + 9;

struct node{
    int ans, l, r;
};

int n, q, a[mxn], lz[mxn * 4];
node f[mxn * 4];

inline void push(int id, int l, int r){
    if(lz[id] < 0){
        int m = l + r >> 1;
        lz[id * 2] = lz[id * 2 + 1] = lz[id];
        f[id * 2] = {m - l + 1, m - l + 1, m - l + 1};
        f[id * 2 + 1] = {r - m, r - m, r - m};
        lz[id] = 0;
    }
    if(lz[id] > 0){
        lz[id * 2] = lz[id * 2 + 1] = lz[id];
        f[id * 2] = {0, 0, 0};
        f[id * 2 + 1] = {0, 0, 0};
        lz[id] = 0;
    }
}

inline void upd(int id, int l, int r, int u, int v, int x){
    if(r < u or v < l) return;
    if(u <= l and r <= v){
        if(x){
            lz[id] = 1;
            f[id].ans = 0;
            f[id].l = f[id].r = 0;
        }else{
            lz[id] = -1;
            f[id].ans = r - l + 1;
            f[id].l = f[id].r = r - l + 1;
        }
        return;
    }
    push(id, l, r);
    int m = l + r >> 1;
    upd(id * 2, l, m, u, v, x);
    upd(id * 2 + 1, m + 1, r, u, v, x);
    f[id].ans = max({f[id * 2].ans, f[id * 2 + 1].ans, f[id * 2].r + f[id * 2 + 1].l});
    f[id].l = f[id * 2].l;
    if(f[id * 2].ans == m - l + 1) f[id].l = max(f[id].l, f[id * 2].ans + f[id * 2 + 1].l);
    f[id].r = f[id * 2 + 1].r;
    if(f[id * 2 + 1].ans == r - m) f[id].r = max(f[id].r, f[id * 2 + 1].ans + f[id * 2].r);
}

node get(int id, int l, int r, int u, int v){
    if(r < u or v < l) return {-1, -1, -1};
    if(u <= l and r <= v) return f[id];
    push(id, l, r);
    int m = l + r >> 1;
    node le = get(id * 2, l, m, u, v);
    node ri = get(id * 2 + 1, m + 1, r, u, v);
    if(le.ans == -1) return ri;
    if(ri.ans == -1) return le;
    node res;
    res.ans = max({le.ans, ri.ans, le.r + ri.l});
    res.l = le.l;
    if(le.l == m - l + 1) res.l = max(res.l, le.l + ri.l);
    res.r = ri.r;
    if(ri.r == r - m) res.r = max(res.r, ri.r + le.r);
    return res;
}

void LonggVuz(){
    cin >> n >> q;
    upd(1, 1, n, 1, n, 0);
    int res = 0;
    while(q--){
        char c; cin >> c;
        if(c == 'A'){
            int k; cin >> k;
            int l = 0, r = n + 1;
            while(r - l > 1){
                int mid = l + r >> 1;
                if(get(1, 1, n, 1, mid).ans >= k) r = mid;
                else l = mid;
            }
            if(r <= n){
                upd(1, 1, n, r - k + 1, r, 1);
            }else{
                ++res;
            }
        }else{
            int l, r; cin >> l >> r;
            upd(1, 1, n, l, r, 0);
        }
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; //cin >> orz;
    while(orz--){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
