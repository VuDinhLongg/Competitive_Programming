// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LonggVuz
#include <LonggVuz.h>
#else
#define debug(...)
#endif

template<class X, class Y> bool maxi(X &a, const Y &b){ return b > a ? a = b, 1 : 0; }
template<class X, class Y> bool mini(X &a, const Y &b){ return b < a ? a = b, 1 : 0; }

#define el cout << '\n'
#define fup(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define fdn(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int64_t i=a; i<=b; i++)
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

int n, k, a[mxn], pf[mxn];

int cal(int m, int l, int r){
    int lo = 1, hi = n;
    while(hi - lo > 1){
        int mid = lo + hi >> 1;
        if(a[mid] <= m) lo = mid;
        else hi = mid;
    }
    int id = lo;
    int ans1 = m * (id - l + 1) - (pf[id] - pf[l - 1]);
    int ans2 = (pf[r] - pf[id]) - m * (r - id);
    return max(ans1, ans2);
}

inline void LonggVuz(){
    cin >> n >> k;
    fo(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    fo(i, 1, n) pf[i] = pf[i - 1] + a[i];
    int res = oo;
    fo(i, 1, n - k + 1){
        int j = i + k - 1;
        int aim = (pf[j] - pf[i - 1]) / k;
        mini(res, min(cal(aim, i, j), cal(aim + 1, i, j)));
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
