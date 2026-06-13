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

vec<int> p;
bool nto(int n){
    if(n == 2 or n == 3) return 1;
    if(n < 2 or n % 2 == 0 or n % 3 == 0) return 0;
    for(int i=5; i*i<=n; i+=6){
        if(n % i == 0 or n % (i + 2) == 0) return 0;
    }
    return 1;
}

void pre(){
    fo(i, 2, 50) if(nto(i)) p.pub(i);
}

int n, l, r;
int cal(int x){
    int m = 0;
    while(m < len(p) and p[m] <= n) ++m;
    int lim = 1 << m;
    int res = 0;
    fo(mask, 1, lim - 1){
        int ans = 1;
        fo(i, 0, m - 1) if(mask >> i & 1){
            ans *= p[i];
        }
        if(__builtin_popcount(mask) & 1){
            res += x / ans;
        }else res -= x / ans;
    }
    return res;
}

inline void LonggVuz(){
    cin >> n >> l >> r;
    cout << cal(r) - cal(l - 1);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    pre();
    signed orz = 1; if(1) cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
