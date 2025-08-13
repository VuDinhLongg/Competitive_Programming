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

const int mod = 1e9 + 7;
const int mxn = 6e3 + 7;

int n, m, l, d, e, a[mxn][mxn], pf[mxn][mxn]; 

bool check(int sz){
    fo(i, 1, n - sz + 1) fo(j, 1, m - sz + 1){
        int cur = pf[i + sz - 1][j + sz - 1] 
                - pf[i - 1][j + sz - 1] - pf[i + sz - 1][j - 1] 
                + pf[i - 1][j - 1];
        if(cur <= e) return 1;
    }
    return 0;
}

void LonggVuz(){
    cin >> n >> m >> l >> d >> e;
    fo(i, 1, l){
        int x, y; cin >> x >> y;
        a[x][y] = 1;
    }
    fo(i, 1, n) fo(j, 1, m){
        pf[i][j] = pf[i - 1][j] + pf[i][j - 1] + a[i][j] - pf[i - 1][j - 1];
    }
    vec<int> v;
    fo(i, d, min(n, m)) if(i % d == 0) v.pub(i);
    int l = -1, r = len(v);
    while(r - l > 1){
        int m = l + r >> 1;
        if(check(v[m])) l = m;
        else r = m;
    }
    cout << v[l];
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
