// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LonggVuz
#include <LonggVuz.h>
#else
#define debug(...)
#endif

template<class X, class Y> bool maxi(X &a, const Y &b){ return b > a ? a = b, 1 : 0; }
template<class X, class Y> bool mini(X &a, const Y &b){ return b < a ? a = b, 1 : 0; }

#define el cout << '\n'
#define fup(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define fdn(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
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
const int mxn = 5e4 + 7;

int n, m, u[168], pos[168];
vec<int> seg[mxn * 4], lz[mxn * 4], nto;

void pre(){
    fo(i, 2, 150) u[i] = i;
    fo(i, 2, 150) if(u[i] == i){
        fup(j, i, 150, i) if(u[j] == j){
            u[j] = i;
        }
    }
    fo(i, 2, 150) if(u[i] == i){
        pos[i] = len(nto);
        nto.pub(i);
    }
}

int mu(int a, int b, int m = mod){
    int res = 1;
    while(b){
        a %= m;
        if(b & 1) res = (res * a) % m;
        a *= a; b /= 2;
    }
    return res;
}

void build(int id, int l, int r){
    if(l == r){
        seg[id].assign(35, 0);
        lz[id].assign(35, 0);
        return;
    }
    int mid = l + r >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    seg[id].assign(35, 0);
    lz[id].assign(35, 0);
}

void push(int id, int l, int r){
    int mid = l + r >> 1;
    fo(i, 0, 34) if(lz[id][i]){
        seg[id * 2][i] += lz[id][i] * (mid - l + 1);
        lz[id * 2][i] += lz[id][i];
        seg[id * 2 + 1][i] += lz[id][i] * (r - mid);
        lz[id * 2 + 1][i] += lz[id][i];
        lz[id][i] = 0;
    }
}

void upd(int id, int l, int r, int u, int v, vec<int> &x){
    if(r < u or v < l) return;
    if(u <= l and r <= v){
        fo(i, 0, 34){
            seg[id][i] += x[i] * (r - l + 1);
            lz[id][i] += x[i];
        }
        return;
    }
    push(id, l, r);
    int mid = l + r >> 1;
    upd(id * 2, l, mid, u, v, x);
    upd(id * 2 + 1, mid + 1, r, u, v, x);
    fo(i, 0, 34) seg[id][i] = seg[id * 2][i] + seg[id * 2 + 1][i];
}

vec<int> get(int id, int l, int r, int u, int v){
    if(r < u or v < l) return {};
    if(u <= l and r <= v) return seg[id];
    push(id, l, r);
    int mid = l + r >> 1;
    vec<int> le = get(id * 2, l, mid, u, v);
    vec<int> ri = get(id * 2 + 1, mid + 1, r, u, v);
    if(le.empty()) return ri;
    if(ri.empty()) return le;
    vec<int> res(35);
    fo(i, 0, 34) res[i] = le[i] + ri[i];
    return res;
}

inline void LonggVuz(){
    cin >> n >> m;
    build(1, 1, n);
    fo(z, 1, m){
        vec<int> tmp = get(1, 1, n, 1, n);
        while(len(tmp) > 5) tmp.pob();
        debug(tmp);
        int t; cin >> t;
        if(t == 0){
            int l, r, p; cin >> l >> r >> p;
            vec<int> v;
            if(l <= r) v = get(1, 1, n, l, r);
            else{
                vec<int> vl = get(1, 1, n, 1, r);
                vec<int> vr = get(1, 1, n, l, n);
                v.assign(35, 0);
                fo(i, 0, 34) v[i] = vl[i] + vr[i];
            }
            int res = 1;
            fo(i, 0, 34){
                res = res * mu(nto[i], v[i], p) % p;
            }
            cout << res, el;
        }else if(t == 1){
            int l, r, x; cin >> l >> r >> x;
            vec<int> d(35, 0);
            while(x > 1){
                ++d[pos[u[x]]];
                x /= u[x];
            }
            if(l <= r) upd(1, 1, n, l, r, d);
            else{
                upd(1, 1, n, 1, r, d);
                upd(1, 1, n, l, n, d);
            }
        }else{
            int l, r, y; cin >> l >> r >> y;
            vec<int> d(35, 0);
            while(y > 1){
                --d[pos[u[y]]];
                y /= u[y];
            }
            if(l <= r) upd(1, 1, n, l, r, d);
            else{
                upd(1, 1, n, 1, r, d);
                upd(1, 1, n, l, n, d);
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    pre();
    signed orz = 1; if(1) cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
