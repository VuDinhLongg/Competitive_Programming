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
#define pb push_back
#define po pop_back
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 8;
const int mxn = 1e6 + 9;

struct fenwick{
    int n; vec<int> f;
    fenwick(int _n){
        n = _n; f.resize(n + 5);
    }
    void upd(int x, int v){
        for(; x >= 1 ; x -= x & -x) f[x] = max(f[x], v);
    }
    int get(int x){
        int s = 0;
        for(; x <= n ; x += x & -x) s = max(s, f[x]);
        return s;
    }
};

void LonggVuz(){
    int n; cin >> n;
    int a[n+5], b[n+5];
    fo(i, 1, n) cin >> a[i], b[i] = a[i];
    sort(b+1, b+n+1);
    fo(i, 1, n) a[i] = lower_bound(b+1, b+n+1, a[i]) - b;
    fenwick f(n);
    int res = 0;
    fo(i, 1, n){
        int g = f.get(a[i]) + 1;
        res = max(res, g);
        f.upd(a[i], g);
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int o = 1; //cin >> o;
    while(o){
        LonggVuz();
        if(--o) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
    return (0 ^ 0);
}
