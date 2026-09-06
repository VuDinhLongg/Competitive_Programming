#include <bits/stdc++.h>
using namespace std;

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define rep(i, n) fo(i, 0, n - 1)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define int long long
#define mxn 500'007

struct node{
    int p1, s1, t1, r1, p0, s0, t0, r0;
};

int n, q, lz[mxn * 4];
string s;
node seg[mxn * 4];

node merge(const node &l, const node &r){
    if(l.r1 == -1) return r;
    if(r.r1 == -1) return l;
    node o;
    o.p1 = max(l.p1, (l.t0 == 0 ? l.t1 : -r.p1) + r.p1);
    o.s1 = max(r.s1, (r.t0 == 0 ? r.t1 : -l.s1) + l.s1);
    o.t1 = l.t1 + r.t1;
    o.r1 = max({l.r1, r.r1, l.s1 + r.p1});
    o.p0 = max(l.p0, (l.t1 == 0 ? l.t0 : -r.p0) + r.p0);
    o.s0 = max(r.s0, (r.t1 == 0 ? r.t0 : -l.s0) + l.s0);
    o.t0 = l.t0 + r.t0;
    o.r0 = max({l.r0, r.r0, l.s0 + r.p0});
    return o;
}

void build(int id, int l, int r){
    if(l == r){
        if(s[l] == '1') seg[id] = {1, 1, 1, 1, 0, 0, 0, 0};
        else seg[id] = {0, 0, 0, 0, 1, 1, 1, 1};
        return;
    }
    int m = l + r >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

void apply(int id){
    swap(seg[id].p1, seg[id].p0);
    swap(seg[id].s1, seg[id].s0);
    swap(seg[id].t1, seg[id].t0);
    swap(seg[id].r1, seg[id].r0);
    lz[id] ^= 1;
}

void push(int id){
    if(lz[id]){
        apply(id * 2);
        apply(id * 2 + 1);
        lz[id] = 0;
    }
}

void update(int id, int l, int r, int u, int v){
    if(r < u or v < l) return;
    if(u <= l and r <= v){
        apply(id);
        return;
    }
    push(id);
    int m = l + r >> 1;
    update(id * 2, l, m, u, v);
    update(id * 2 + 1, m + 1, r, u, v);
    seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

node query(int id, int l, int r, int u, int v){
    if(r < u or v < l) return {-1, -1, -1, -1, -1, -1, -1, -1};
    if(u <= l and r <= v) return seg[id];
    push(id);
    int m = l + r >> 1;
    return merge(query(id * 2, l, m, u, v), query(id * 2 + 1, m + 1, r, u, v));
}

inline void solve(){
    cin >> n >> q >> s;
    s = " " + s;
    build(1, 1, n);
    while(q--){
        int t, l, r; cin >> t >> l >> r;
        if(t == 1){
            update(1, 1, n, l, r);
        }else{
            node res = query(1, 1, n, l, r);
            cout << res.r1, el;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #define name "icpc"
    if(fopen(name".inp", "r")){
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    
    int o = 1; ///cin >> o;
    while(o --> 0) solve();
}