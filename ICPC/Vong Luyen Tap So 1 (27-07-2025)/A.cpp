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

bool check(pe &a, pe &b, pe &c){
    int a1 = a.fi, a2 = a.se;
    int b1 = b.fi, b2 = b.se;
    int c1 = c.fi, c2 = c.se;
    int x1 = b1 - a1, y1 = b2 - a2;
    int x2 = c1 - a1, y2 = c2 - a2;
    return x1 * y2 == y1 * x2;
}

void LonggVuz(){
    int n; cin >> n;
    pe a[n+5];
    fo(i, 1, n){
        cin >> a[i].fi >> a[i].se;
    }
    int res = n * (n - 1) * (n - 2) / 6;
    fo(i, 1, n - 2) fo(j, i + 1, n - 1) fo(k, j + 1, n){
        if(check(a[i], a[j], a[k])) --res;
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
