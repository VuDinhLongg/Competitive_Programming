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
    int n; vec<vec<int>> f;
    fenwick(int _n){
        n = _n; f.resize(n + 5, vec<int>(5));
    }
    int sum(int a, int b){ return a + b; }
    void upd(int x, int y, int v){
        for(; x >= 1 ; x -= x & -x) f[x][y] = sum(f[x][y], v);
    }
    int get(int x, int y){
        int s = 0;
        for(; x <= n ; x += x & -x) s = sum(s, f[x][y]);
        return s;
    }
};

void LonggVuz(){
    int n; cin >> n;
    int a[n+5];
    fo(i, 1, n) cin >> a[i];
    fenwick f(n);
    fo(i, 1, n){
        f.upd(a[i], 1, 1);
        fo(j, 1, 2){
            int g = f.get(a[i] + 1, j);
            f.upd(a[i], j + 1, g);
        }
    }
    cout << f.get(1, 3);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
