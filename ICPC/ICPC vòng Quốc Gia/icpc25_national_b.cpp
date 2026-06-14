/*======================
   Author : @LonggVuz
======================*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define orz(...) 2005
#endif

#define el cout << '\n'
#define all(x) begin(x), end(x)
#define fix(x) fixed << setprecision(x)
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 200'007
#define ai3 array<int, 3>
#define ai4 array<int, 4>
#define pii pair<int, int>
#define fi first
#define se second

int n;
pii a[mxn];

inline void LonggVuz(){
    cin >> n;
    fo(i, 1, n){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1, a+n+1, [&](pii &x, pii &y){
        return x.fi + x.se > y.fi + y.se;
    });
    int res = 0, t = 0;
    fo(i, 1, n){
        if(a[i].fi > t){
            a[i].se += a[i].fi - t;
            t = a[i].fi;
        }
        res += a[i].se * a[i].se;
    }
    cout << res, el;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(1) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}