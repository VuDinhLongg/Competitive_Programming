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

int n, m, a[mxn], b[mxn], c[mxn];

void LonggVuz(){
    cin >> n >> m;
    fo(i, 1, n) cin >> a[i];
    fo(i, 1, m) cin >> b[i];
    sort(b+1, b+m+1);
    int res = oo;
    fo(i, 1, n){
        int id = lower_bound(b+1, b+m+1, a[i]) - b;
        c[i] = oo;
        if(id <= m) c[i] = min(c[i], b[id] - a[i]);
        if(id > 1){
            --id;
            c[i] = min(c[i], a[i] - b[id]);
        }
        res = min(res, c[i]);
    }
    cout << res;
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
