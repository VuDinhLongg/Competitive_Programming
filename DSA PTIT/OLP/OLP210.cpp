// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <LonggVuz.h>
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
#define dub double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e7 + 7;

int n, m, a[100001], f[mxn], pf[mxn];

void pre(int n = 1e7){
    f[0] = 1;
    fo(i, 1, n) f[i] = f[i - 1] * i % m;
    fo(i, 1, n) pf[i] = (pf[i - 1] + f[i] * i % m) % m;
}

int cal(int x){
    if(x & 1){
        int r1 = (x + 1) / 2; r1 %= m;
        int r2 = x % m;
        int r3 = x % m;
        return r1 * r2 % m * r3 % m;
    }else{
        int r1 = x / 2; r1 %= m;
        int r2 = (x + 1) % m;
        int r3 = x % m;
        return r1 * r2 % m * r3 % m;
    }
    return 0 ^ 0;
}

inline void LonggVuz(){
    cin >> n >> m;
    fo(i, 1, n) cin >> a[i];
    pre();
    int res = 0;
    fo(i, 1, n){
        if(a[i] >= m) res += pf[m - 1];
        else res += pf[a[i]];
        res += cal(a[i]);
        res %= m;
    }
    cout << res;
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
