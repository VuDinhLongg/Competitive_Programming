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
const int mxn = 2e5 + 7;

vec<int> bs; int base = 167;

void pre(int n){
    bs.resize(n + 5, 1);
    fo(i, 1, n) bs[i] = bs[i - 1] * base % mod;
}

struct Hash{
    vec<int> h;
    Hash(string &str){
        int n = len(str);
        str.insert(begin(str), ' ');
        h.resize(n + 5);
        fo(i, 1, n) h[i] = (h[i - 1] * base + str[i] - '0' + 1) % mod;
    }
    int get(int l, int r){
        return (h[r] - h[l - 1] * bs[r - l + 1] % mod + mod) % mod;
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
        lz[id * 2] += lz[id];
        lz[id * 2 + 1] += lz[id];
        f[id * 2] += lz[id];
        f[id * 2 + 1] += lz[id];
        lz[id] = 0;
    }
    void range(int id, int l, int r, int u, int v, int x){
        if(r < u or v < l) return;
        if(u <= l and r <= v){
            lz[id] += x;
            f[id] += x;
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
            f[id] = x;
            return;
        }
        int m = (l + r) >> 1;
        if(i <= m) point(id * 2, l, m, i, x);
        else point(id * 2 + 1, m + 1, r, i, x);
        f[id] = (f[id * 2] * bs[r - m] % mod) + f[id * 2 + 1];
        if(f[id] >= mod) f[id] -= mod;
    }
    int get(int id, int l, int r, int u, int v){
        if(r < u or v < l) return -oo;
        if(u <= l and r <= v) return f[id];
        int m = (l + r) >> 1;
        int le = get(id * 2, l, m, u, v);
        int ri = get(id * 2 + 1, m + 1, r, u, v);
        if(le == -oo) return ri;
        if(ri == -oo) return le;
        int res = (le * bs[min(r, v) - m] % mod) + ri;
        if(res >= mod) res -= mod;
        return res;
    }
};

void LonggVuz(){
    pre(2e5);
    string a; cin >> a;
    string b = a;
    reverse(all(b));
    int n = len(a);
    Hash ha(a), hb(b);
    segtree sa(n), sb(n);
    fo(i, 1, n){
        sa.point(i, a[i] - '0' + 1);
        sb.point(i, b[i] - '0' + 1);
    }
    int q; cin >> q;
    while(q--){
        char c; cin >> c;
        if(c == 'c'){
            int u; char x; cin >> u >> x;
            sa.point(u, x - '0' + 1);
            a[u] = x;
            sb.point(n - u + 1, x - '0' + 1);
            b[n - u + 1] = x;
        }else{
            int l, r; cin >> l >> r;
            int get_a = sa.get(l, r);
            int get_b = sb.get(n - r + 1, n - l + 1);
            if(get_a == get_b) cout << "YES\n";
            else cout << "NO\n";
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
