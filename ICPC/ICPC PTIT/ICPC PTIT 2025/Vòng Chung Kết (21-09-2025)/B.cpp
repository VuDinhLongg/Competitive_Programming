// LonggVuz
#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<LonggVuz.h>
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
#define float double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e5 + 7;

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
        for(; x <= n; x += x & -x) s += g[x];
        return s;
    }
};

int n, a[mxn], b[mxn], len;

bool check(int x){
    int res = 0, cur = 0;
    fenwick f(n + n);
    f.upd1(cur + n, 1);
    fo(i, 1, n){
        if(a[i] <= x) --cur;
        else ++cur;
        res += f.getn(cur + n + 1);
        f.upd1(cur + n, 1);
    }
    return res >= len / 2 + 1;
}

void LonggVuz(){
    cin >> n;
    fo(i, 1, n) cin >> a[i], b[i] = a[i];
    sort(b+1, b+n+1);
    len = n * (n + 1) / 2;
    int l = 0, r = n + 1;
    while(r - l > 1){
        int m = l + r >> 1;
        if(check(b[m])) r = m;
        else l = m;
    }
    debug(r);
    cout << b[r];
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
