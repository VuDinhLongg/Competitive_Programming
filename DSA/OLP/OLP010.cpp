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
const int mxn = 1e5 + 7;

int n, a[mxn];

inline void LonggVuz(){
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    int res = 0, l = 1;
    multiset<int> ms;
    fo(r, 1, n){
        ms.insert(a[r]);
        while(len(ms) >= 3){
            int mx = *ms.rbegin();
            auto it = ms.begin();
            int m1 = *it;
            ++it;
            int m2 = *it;
            if(m1 + m2 > mx) break;
            ms.erase(ms.find(a[l]));
            ++l;
        }
        if(len(ms) >= 3){
            res = max(res, r - l + 1);
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
