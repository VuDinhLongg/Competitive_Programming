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



void LonggVuz(){
    int n; cin >> n;
    int a[n+5];
    fo(i, 1, n) cin >> a[i];
    int res = 0;
    fo(i, 1, n - 2) fo(j, i + 1, n - 1) fo(k, j + 1, n){
        int x = min({a[i], a[j], a[k]});
        int z = max({a[i], a[j], a[k]});
        int y = a[i] + a[j] + a[k] - x - z;
        if(x < y and y < z and x + y > z) ++res;
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
