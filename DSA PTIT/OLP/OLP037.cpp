// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LonggVuz
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
const int mxn = 1e6 + 7;

struct fenwick{
    int n; vec<int> f, g;
    fenwick(int _n){
        n = _n; f.resize(n + 5); g.resize(n + 5);
    }
    void upd1(int x, int v){
        for(; x >= 1 ; x -= x & -x) g[x] += v;
    }
    void updn(int x, int v){
        for(; x <= n ; x += x & -x) f[x] += v;
    }
    int get1(int x){
        int s = 0;
        for(; x >= 1 ; x -= x & -x) s += f[x];
        return s;
    }
    int getn(int x){
        int s = 0;
        for(; x <= n ; x += x & -x) s += g[x];
        return s;
    }
};

inline void LonggVuz(){
    int n; cin >> n;
    int a[n+5];
    fo(i, 1, n) cin >> a[i];
    int res = 0;
    fenwick f1(n), f2(n);
    fo(i, 1, n){
        res += f2.getn(a[i] + 1);
        int g = f1.getn(a[i] + 1);
        f2.upd1(a[i], g);
        f1.upd1(a[i], 1);
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; if(1) cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
