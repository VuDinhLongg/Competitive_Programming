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

struct fenwick{
    int n; vec<int> f;
    fenwick(int _n){
        n = _n; f.resize(n + 5);
    }
    int sum(int a, int b){ return a + b; }
    void upd(int x, int v){
        for(; x <= n ; x += x & -x) f[x] = sum(f[x], v);
    }
    int get(int x){
        int s = 0;
        for(; x >= 1 ; x -= x & -x) s = sum(s, f[x]);
        return s;
    }
};

void LonggVuz(){
    int n; cin >> n;
    int a[n+5];
    fenwick f(n);
    fo(i, 1, n){
        cin >> a[i];
        f.upd(i, a[i]);
        f.upd(i + 1, -a[i]);
    }
    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r, k; cin >> l >> r >> k;
            f.upd(l, k);
            f.upd(r + 1, -k);
        }else{
            int u; cin >> u;
            cout << f.get(u); el;
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
