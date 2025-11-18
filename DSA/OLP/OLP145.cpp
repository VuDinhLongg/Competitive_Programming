// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LonggVuz
#include <LonggVuz.h>
#else
#define debug(...)
#define print(...)
#endif

template<class X, class Y> bool maxi(X &a, const Y &b){ return b > a ? a = b, 1 : 0; }
template<class X, class Y> bool mini(X &a, const Y &b){ return b < a ? a = b, 1 : 0; }

#define el cout << '\n'
#define fup(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define fdn(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define out(x) return void(cout << (x))
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define dub double
#define int int64_t
#define pii pair<int, int>
#define pip pair<int, pii>
#define ppi pair<pii, int>
#define fi first
#define se second

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

struct node{
    int l, r, v;
    node(){
        l = oo;
        r = -oo;
        v = -1;
    }
    node(int _l, int _r, int _v){
        l = _l; r = _r; v = _v;
    }
};

int n, q, a[mxn], com[mxn];
node seg[mxn * 4];

node merge(const node &x, const node &y){
    node a;
    a.l = min(x.l, y.l);
    a.r = max(x.r, y.r);
    a.v = oo;
    if(x.v != -1) mini(a.v, x.v);
    if(y.v != -1) mini(a.v, y.v);
    if(y.l < oo and x.r < oo) mini(a.v, y.l - x.r);
    return a;
}

void upd(int id, int l, int r, int i, int x){
    if(l == r){
        if(seg[id].v == -1) seg[id] = node(x, x, oo);
        else seg[id] = node(x, x, 0);
        return;
    }
    int m = l + r >> 1;
    if(i <= m) upd(id * 2, l, m, i, x);
    else upd(id * 2 + 1, m + 1, r, i, x);
    seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

node get(int id, int l, int r, int u, int v){
    if(r < u or v < l) return node(-1, -1, -1);
    if(u <= l and r <= v) return seg[id];
    int m = l + r >> 1;
    node le = get(id * 2, l, m, u, v);
    node ri = get(id * 2 + 1, m + 1, r, u, v);
    if(le.v == -1) return ri;
    if(ri.v == -1) return le;
    return merge(le, ri);
}

inline void LonggVuz(){
    cin >> n >> q;
    vec<int> zip;
    fo(i, 1, n){
        cin >> a[i];
        zip.pub(a[i]);
    }
    vec<pip> tv;
    fo(i, 1, q){
        int t; cin >> t;
        if(t == 1){
            int p; cin >> p;
            tv.pub({t, {p, 0}});
            zip.pub(p);
        }else{
            int l, r; cin >> l >> r;
            tv.pub({t, {l, r}});
            zip.pub(l);
            zip.pub(r);
        }
    }
    sort(all(zip));
    zip.erase(unique(all(zip)), end(zip));
    fo(i, 1, n){
        int pos = lower_bound(all(zip), a[i]) - begin(zip) + 1;
        com[pos] = a[i];
        a[i] = pos;
        upd(1, 1, len(zip), pos, com[pos]);
    }
    for(auto &[t, lr] : tv){
        auto &[l, r] = lr;
        if(t == 1){
            int pos = lower_bound(all(zip), l) - begin(zip) + 1;
            com[pos] = l;
            l = pos;
            upd(1, 1, len(zip), pos, com[pos]);
        }else{
            int pos1 = lower_bound(all(zip), l) - begin(zip) + 1;
            int pos2 = lower_bound(all(zip), r) - begin(zip) + 1;
            com[pos1] = l;
            com[pos2] = r;
            l = pos1;
            r = pos2;
            node res = get(1, 1, len(zip), l, r);
            // debug(res.l, res.r, res.v);
            cout << (res.v < oo ? res.v : -1), el;
        }
    }
}

signed main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    
    signed hehe = 1; if(false) cin >> hehe;
    for(signed hihi = 1; hihi <= hehe; ++hihi){
        print(hihi);
        LonggVuz();
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
