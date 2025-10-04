// HLD + SegTree
// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
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
const int mxn = 5e4 + 7;

int n, q, seg[mxn * 4], lz[mxn * 4];
vec<int> ke[mxn];
int sz[mxn], par[mxn];
int head[mxn], pos[mxn], h[mxn], cnt, a[mxn];

void dfs(int u, int p = 0){
    sz[u] = 1;
    int id = 0;
    fo(i, 0, len(ke[u]) - 1){
        int v = ke[u][i];
        if(v == p) continue;
        par[v] = u;
        h[v] = h[u] + 1;
        dfs(v, u);
        if(sz[v] > sz[ke[u][id]]) id = i;
        sz[u] += sz[v];
    }
    swap(ke[u][0], ke[u][id]);
}

void hld(int u){
    pos[u] = ++cnt;
    a[cnt] = u;
    for(int &v : ke[u]) if(v != par[u]){
        if(v == ke[u][0]) head[v] = head[u];
        else head[v] = v;
        hld(v);
    }
}

void push(int id, int l, int r){
    int m = l + r >> 1;
    seg[id * 2] += lz[id] * (m - l + 1);
    lz[id * 2] += lz[id];
    seg[id * 2 + 1] += lz[id] * (r - m);
    lz[id * 2 + 1] += lz[id];
    lz[id] = 0;
}

void range(int id, int l, int r, int u, int v){
    if(r < u or v < l) return;
    if(u <= l and r <= v){
        seg[id] += (r - l + 1);
        lz[id] += 1;
        return;
    }
    if(lz[id]) push(id, l, r);
    int m = l + r >> 1;
    range(id * 2, l, m, u, v);
    range(id * 2 + 1, m + 1, r, u, v);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v){
    if(r < u or v < l) return 0;
    if(u <= l and r <= v) return seg[id];
    if(lz[id]) push(id, l, r);
    int m = l + r >> 1;
    return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
}

void update(int x, int y){
    while(head[x] != head[y]){
        if(h[head[x]] < h[head[y]]) swap(x, y);
        range(1, 1, n, pos[head[x]], pos[x]);
        x = par[head[x]];
    }
    if(h[x] > h[y]) swap(x, y);
    range(1, 1, n, pos[x], pos[y]);
}

inline void LonggVuz(){
    cin >> n >> q;
    fo(i, 2, n){
        int x, y; cin >> x >> y;
        ke[x].pub(y);
        ke[y].pub(x);
    }
    dfs(1);
    hld(1);
    while(q--){
        int x, y; cin >> x >> y;
        update(x, y);
    }
    int res = 0;
    fo(i, 1, n) res = max(res, get(1, 1, n, pos[i], pos[i]));
    cout << res;
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
