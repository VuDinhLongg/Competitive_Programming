// LonggVuz
#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<LonggVuz.h>
#else
#define debug(...)
#endif

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
#define float double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

#define bit(n, i) ((n) >> (i) & 1)
int n, k, a[16];

inline int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int get(int x){
    int res = x, lim = 1 << n;
    fo(mask, 1, lim - 1){
        int c = __builtin_popcount(mask);
        if(c & 1){
            int t = 1;
            bool ok = 1;
            fo(i, 0, n - 1) if(bit(mask, i)){
                t = t / gcd(t, a[i]) * a[i];
                if(t > x){
                    ok = 0; break;
                }
            }
            if(ok) res -= x / t;
        }else{
            int t = 1;
            bool ok = 1;
            fo(i, 0, n - 1) if(bit(mask, i)){
                t = t / gcd(t, a[i]) * a[i];
                if(t > x){
                    ok = 0; break;
                }
            }
            if(ok) res += x / t;
        }
    }
    return res;
}

void LonggVuz(){
    cin >> n >> k;
    fo(i, 0, n - 1) cin >> a[i];
    int l = 0, r = 1e18;
    while(r - l > 1){
        int mid = l + r >> 1;
        if(get(mid) >= k) r = mid;
        else l = mid;
    }
    cout << r;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; if(1) cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
