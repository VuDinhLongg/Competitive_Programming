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
const int mxn = 1e5 + 7;

struct segtree{
    int n; vec<int> f, lz;
    segtree(int _n){
        n = _n; f.resize(n * 4 + 5); lz.resize(n * 4 + 5);
    }
    int sum(int a, int b){ return a + b; }
    int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }
    void range(int l, int r, int x){ range(1, 1, n, l, r, x); }
    void point(int i, int x){ point(1, 1, n, i, x); }
    int get(int l, int r){ return get(1, 1, n, l, r); }

    void push(int id, int l, int r){
        
    }
    void range(int id, int l, int r, int u, int v, int x){
        if(r < u or v < l) return;
        if(u <= l and r <= v){
            return;
        }
        if(lz[id]) push(id, l, r);
        int m = (l + r) >> 1;
        range(id * 2, l, m, u, v, x);
        range(id * 2 + 1, m + 1, r, u, v, x);
        f[id] = max(f[id * 2], f[id * 2 + 1]);
    }
    void point(int id, int l, int r, int i, int x){
        if(l == r){
            maxi(f[id], x); return;
        }
        if(lz[id]) push(id, l, r);
        int m = (l + r) >> 1;
        if(i <= m) point(id * 2, l, m, i, x);
        else point(id * 2 + 1, m + 1, r, i, x);
        f[id] = max(f[id * 2], f[id * 2 + 1]);
    }
    int get(int id, int l, int r, int u, int v){
        if(r < u or v < l) return -oo;
        if(u <= l and r <= v) return f[id];
        if(lz[id]) push(id, l, r);
        int m = (l + r) >> 1;
        int le = get(id * 2, l, m, u, v);
        int ri = get(id * 2 + 1, m + 1, r, u, v);
        return max(le, ri);
    }
};

struct node{
    int a, b, h;  
};

int n;
node a[mxn];

inline void LonggVuz(){
    cin >> n;
    vec<int> zip;
    fo(i, 1, n){
        cin >> a[i].a >> a[i].b >> a[i].h;
        zip.pub(a[i].a);
        zip.pub(a[i].b);
    }
    sort(all(zip));
    zip.erase(unique(all(zip)), end(zip));
    fo(i, 1, n){
        a[i].a = lower_bound(all(zip), a[i].a) - begin(zip) + 1;
        a[i].b = lower_bound(all(zip), a[i].b) - begin(zip) + 1;
    }
    sort(a+1, a+n+1, [&](node &x, node &y){
        if(x.b == y.b) return x.a > y.a;
        return x.b > y.b;
    });
    int res = 0;
    segtree seg(len(zip));
    fo(i, 1, n){
        int g = seg.get(1, a[i].b - 1);
        maxi(res, g + a[i].h);
        seg.point(a[i].a, g + a[i].h);
    }
    cout << res;
}

signed main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    
    signed o_o = 1; if(false) cin >> o_o;
    fo(_, 1, o_o) print(_), LonggVuz();
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
