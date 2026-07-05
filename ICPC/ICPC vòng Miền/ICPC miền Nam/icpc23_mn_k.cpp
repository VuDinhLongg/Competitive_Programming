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
const int mxn = 1e6 + 7;



inline void LonggVuz(){
    int n; cin >> n;
    int a[n+5];
    fo(i, 1, n) cin >> a[i];

    auto check = [&](int m){
        fo(i, 1, n) if(a[i] >= m){
            int l = i - 1, x = m - 1;
            while(l >= 1 and a[l] >= x and x >= 1){
                --x;
                --l;
            }
            if(x > 0) continue;
            int r = i + 1, y = m - 1;
            while(r <= n and a[r] >= y and y >= 1){
                --y;
                ++r;
            }
            if(y > 0) continue;
            return 1;
        }
        return 0;
    };

    int l = 0, r = n + 1;
    while(r - l > 1){
        int m = l + r >> 1;
        if(check(m)) l = m;
        else r = m;
    }
    cout << l;
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
