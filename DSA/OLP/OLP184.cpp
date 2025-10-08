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
#define fo(i, a, b) for(int64_t i=a; i<=b; i++)
#define fd(i, a, b) for(int32_t i=a; i>=b; i--)
#define out(x) return void(cout << (x))
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define dub long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;
const dub eps = 1e-18;

dub x, y, R;

dub dis(dub a, dub b, dub c, dub d){
    return (a - c) * (a - c) + (b - d) * (b - d);
}

inline void LonggVuz(){
    cin >> x >> y >> R;
    int res = 0;
    fo(i, -2e5, 2e5){
        {
            int l = ceil(y) - 1, r = 2e5 + 1;
            while(r - l > 1){
                int m = l + r >> 1;
                if(dis(x, y, i, m) <= R * R + eps) l = m;
                else r = m;
            }
            if(l >= ceil(y)){
                res += l - ceil(y) + 1;
            }
        }
        {
            int l = -2e5 - 1, r = ceil(y);
            while(r - l > 1){
                int m = l + r >> 1;
                if(dis(x, y, i, m) <= R * R + eps) r = m;
                else l = m;
            }
            if(r < ceil(y)){
                res += ceil(y) - r;
            }
        }
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
