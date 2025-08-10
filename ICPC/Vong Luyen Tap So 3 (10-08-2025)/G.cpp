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
#define pub push_back
#define pob pop_back
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e5 + 7;

int n, q, a[mxn];

struct mstree{
    vec<multiset<int>> f;
    mstree(){
        f.resize(n * 4 + 5); build(1, 1, n);
    }
    void point(int i, int x){ point(1, 1, n, i, x); }
    int get(int l, int r, int k){ return get(1, 1, n, l, r, k); }
    // Functions
    void build(int id, int l, int r){
        if(l == r){
            f[id].insert(a[l]);
            return;
        }
        int m = (l + r) >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        f[id] = f[id * 2 + 1];
        for(auto &x : f[id * 2]) f[id].insert(x);
    }
    void point(int id, int l, int r, int i, int x){
        if(l == r){
            f[id].clear();
            f[id].insert(x);
            return;
        }
        int m = (l + r) >> 1;
        if(i <= m) point(id * 2, l, m, i, x);
        else point(id * 2 + 1, m + 1, r, i, x);
        if(f[id].count(a[i])) f[id].erase(f[id].find(a[i]));
        f[id].insert(x);
    }
    int get(int id, int l, int r, int u, int v, int k){
        if(r < u or v < l) return oo;
        if(u <= l and r <= v){
            auto it = f[id].upper_bound(k);
            if(it == f[id].end()) return oo;
            return *it;
        }
        int m = (l + r) >> 1;
        int le = get(id * 2, l, m, u, v, k);
        int ri = get(id * 2 + 1, m + 1, r, u, v, k);
        return min(le, ri);
    }
};

void LonggVuz(){
    cin >> n >> q;
    fo(i, 1, n) cin >> a[i];
    mstree s;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int u, val; cin >> u >> val;
            s.point(u, val);
            a[u] = val;
        }else{
            int l, r, k; cin >> l >> r >> k;
            int res = s.get(l, r, k);
            cout << (res < oo ? res : -1); el;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; //cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
