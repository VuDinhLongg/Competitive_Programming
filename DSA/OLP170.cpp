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

const int mod = 1e18 + 7;
const int oo = 1e18 + 7;
const int mxn = 5e4 + 7;

#define i128 __int128_t
int n, base = 1e8 + 7;
vec<int> a[mxn];
map<int, int> mp;

inline void LonggVuz(){
    cin >> n;
    fo(i, 1, n){
        a[i].resize(5);
        fo(j, 0, 4) cin >> a[i][j];
        sort(all(a[i]));
    }
    int res = 0;
    fo(i, 1, n){
        fo(mask, 1, 31){
            int cur = 0;
            fo(j, 0, 4) if(mask >> j & 1){
                cur = ((i128)cur * base + (a[i][j] + 1000001)) % mod;
            }
            if(__builtin_popcount(mask) & 1){
                res += mp[cur];
            }else{
                res -= mp[cur];
            }
        }
        fo(mask, 1, 31){
            int cur = 0;
            fo(j, 0, 4) if(mask >> j & 1){
                cur = ((i128)cur * base + (a[i][j] + 1000001)) % mod;
            }
            ++mp[cur];
        }
    }
    cout << n * (n - 1) / 2 - res;
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
