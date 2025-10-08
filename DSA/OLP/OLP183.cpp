// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LonggVuz
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
const int mxn = 1e6 + 7;

int mu(int a, int b, int m = mod){
    int res = 1;
    while(b){
        a %= m;
        if(b & 1) res = (res * a) % m;
        a *= a; b /= 2;
    }
    return res;
}

int f[mxn], ivf[mxn];
void pre(int n){
    f[0] = 1;
    fo(i, 1, n) f[i] = f[i - 1] * i % mod;
    ivf[n] = mu(f[n], mod - 2);
    fd(i, n, 1) ivf[i - 1] = ivf[i] * i % mod;
}

int C(int n, int k){
    if(n < k) return 0;
    return f[n] * ivf[k] % mod * ivf[n - k] % mod;
}

inline void LonggVuz(){
    pre(1e6);
    int n, m; cin >> n >> m;
    int res = 1;
    for(int i=2; i*i<=m; i++){
        if(m % i == 0){
            int cnt = 0;
            while(m % i == 0){
                ++cnt;
                m /= i;
            }
            res *= C(cnt + n - 1, n - 1);
            res %= mod;
        }
    }
    if(m > 1){
        res *= n;
        res %= mod;
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
