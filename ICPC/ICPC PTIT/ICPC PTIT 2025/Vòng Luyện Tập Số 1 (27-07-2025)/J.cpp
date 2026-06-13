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

#define pe pair<int, int>
#define fi first
#define se second

void LonggVuz(){
    int n; cin >> n;
    pe a[n+5];
    fo(i, 1, n){
        cin >> a[i].fi >> a[i].se;
    }
    int res = a[1].se, mx = a[1].fi + a[1].se, ko = 0;
    sort(a+2, a+n+1, [&](pe x, pe y){
        return x.fi < y.fi;
    });
    fo(i, 2, n){
        res += a[i].se + max(a[i].fi - mx, ko);
        mx = max(mx, a[i].fi + a[i].se);
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
