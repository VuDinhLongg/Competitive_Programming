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
#define out(x) return void(cout << (x));
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define float double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 3e5 + 7;

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

int n, a[mxn], dp[mxn];

void LonggVuz(){
    cin >> n;
    fo(i, 1, n){
        cin >> a[i];
        ++a[i];
    }
    int res = 0;
    fenwick f(n);
    fo(i, 1, n){
        res += f.getn(a[i] + 1);
        f.upd1(a[i], 1);
    }
    cout << res, el;
    fo(i, 1, n - 1){
        int sub = a[i] - 1;
        int add= n - a[i];
        res = res - sub + add;
        cout << res, el;
    }
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
