// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LonggVuz
#include <LonggVuz.h>
#else
#define debug(...)
#define print(...)
#endif

template<class X, class Y> bool maxi(X &a, const Y &b){ return b > a ? a = b, 1 : 0; }
template<class X, class Y> bool mini(X &a, const Y &b){ return b < a ? a = b, 1 : 0; }

#define el cout << '\n'
#define fup(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define fdn(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
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

#define pii pair<int, int>
#define pip pair<int, pii>
#define ppi pair<pii, int>
#define fi first
#define se second

int cal1(pii a[], int n){
    sort(a+1, a+n+1, [&](pii &x, pii &y){
        if(x.fi == y.fi) return x.se < y.se;
        return x.fi < y.fi;
    });
    auto get = [&](int id){
        int ans = 0;
        fo(i, 1, n) ans += abs(a[i].fi - a[id].fi) + abs(a[i].se - a[id].se);
        ans -= (id - 1 + 1) * (id - 1) / 2;
        ans -= (n - id + 1) * (n - id) / 2;
        return ans;
    };
    int mid = (n + 1) / 2;
    return min(get(mid), get(mid + 1));
}

int cal2(pii a[], int n){
    sort(a+1, a+n+1, [&](pii &x, pii &y){
        if(x.se == y.se) return x.fi < y.fi;
        return x.se < y.se;
    });
    auto get = [&](int id){
        int ans = 0;
        fo(i, 1, n) ans += abs(a[i].fi - a[id].fi) + abs(a[i].se - a[id].se);
        ans -= (id - 1 + 1) * (id - 1) / 2;
        ans -= (n - id + 1) * (n - id) / 2;
        return ans;
    };
    int mid = (n + 1) / 2;
    return min(get(mid), get(mid + 1));
}

inline void LonggVuz(){
    int n; cin >> n;
    pii a[n+5], b[n+5];
    fo(i, 1, n){
        cin >> a[i].fi >> a[i].se;
        b[i] = a[i];
    }
    cout << min(cal1(a, n), cal2(b, n));
}

signed main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    
    signed hehe = 1; if(false) cin >> hehe;
    for(signed hihi = 1; hihi <= hehe; ++hihi){
        print(hihi);
        LonggVuz();
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
