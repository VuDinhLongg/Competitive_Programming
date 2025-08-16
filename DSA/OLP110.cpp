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
const int mxn = 1e6 + 7;

vec<int> base, pf; int bs = 167;

void pre(int n){
    base.resize(n + 5, 1);
    pf.resize(n + 5, 1);
    fo(i, 1, n){
        base[i] = base[i - 1] * bs % mod;
        pf[i] = pf[i - 1] + base[i];
        if(pf[i] >= mod) pf[i] -= mod;
    }
}

struct Hash{
    vec<int> h;
    Hash(string &str){
        int n = len(str);
        str.insert(begin(str), ' ');
        h.resize(n + 5);
        fo(i, 1, n) h[i] = (h[i - 1] * bs + str[i] - '0' + 1) % mod;
    }
    int get(int l, int r){
        return (h[r] - h[l - 1] * base[r - l + 1] % mod + mod) % mod;
    }
};

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
    // Functions
    void push(int id, int l, int r){
        int m = (l + r) >> 1;
        lz[id * 2] = lz[id];
        lz[id * 2 + 1] = lz[id];
        f[id * 2] = lz[id] * pf[m - l] % mod;
        f[id * 2 + 1] = lz[id] * pf[r - m - 1] % mod;
        lz[id] = 0;
    }
    void range(int id, int l, int r, int u, int v, int x){
        if(r < u or v < l) return;
        if(u <= l and r <= v){
            lz[id] = x;
            f[id] = x * pf[r - l] % mod;
            return;
        }
        if(lz[id]) push(id, l, r);
        int m = (l + r) >> 1;
        range(id * 2, l, m, u, v, x);
        range(id * 2 + 1, m + 1, r, u, v, x);
        f[id] = f[id * 2] * base[r - m] + f[id * 2 + 1];
        f[id] %= mod;
    }
    void point(int id, int l, int r, int i, int x){
        if(l == r){
            f[id] = x;
            return;
        }
        int m = (l + r) >> 1;
        if(i <= m) point(id * 2, l, m, i, x);
        else point(id * 2 + 1, m + 1, r, i, x);
        f[id] = f[id * 2] * base[r - m] + f[id * 2 + 1];
        f[id] %= mod;
    }
    int get(int id, int l, int r, int u, int v){
        if(r < u or v < l) return -oo;
        if(u <= l and r <= v) return f[id];
        if(lz[id]) push(id, l, r);
        int m = (l + r) >> 1;
        int le = get(id * 2, l, m, u, v);
        int ri = get(id * 2 + 1, m + 1, r, u, v);
        if(min(le, ri) == -oo) return max(le, ri);
        return (le * base[min(r, v) - m] + ri) % mod;
    }
};

void LonggVuz(){
    pre(1e5);
    int n, q; cin >> n >> q;
    string a; cin >> a;
    Hash h(a);
    segtree s(n);
    fo(i, 1, n) s.point(i, a[i] - '0' + 1);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r; char x; cin >> l >> r >> x;
            s.range(l, r, x - '0' + 1);
        }else{
            int l, r, d; cin >> l >> r >> d;
            int len = r - l + 1;
            if(d <= len and s.get(l, r - d) == s.get(l + d, r)){
                cout << "YES\n";
            }else cout << "NO\n";
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
