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
#define mxn 1'000'007
#define ai3 array<int, 3>
#define ai4 array<int, 4>
#define pii pair<int, int>
#define fi first
#define se second

int n, xa, ya, xb, yb;
pii a[10];

int dis(pii x, pii y){
    return abs(x.fi - y.fi) + abs(x.se - y.se);
}

inline void LonggVuz(){
    cin >> n;
    fo(i, 1, n){
        cin >> a[i].fi >> a[i].se;
    }
    cin >> xa >> ya >> xb >> yb;
    sort(a+1, a+n+1);
    int res = 1e18;
    fo(i, 0, n){
        pii b[10];
        fo(j, 1, n) b[j] = a[j];
        do{
            int ans = 0;
            int cx = xa, cy = ya, cur = 0;
            fo(j, 1, i){
                ans += dis(b[j], {cx, cy}) * cur;
                cx = b[j].fi;
                cy = b[j].se;
                ++cur;
            }
            ans += dis({xa, ya}, {cx, cy}) * cur;
            cx = xb, cy = yb, cur = 0;
            fo(j, i + 1, n){
                ans += dis(b[j], {cx, cy}) * cur;
                cx = b[j].fi;
                cy = b[j].se;
                ++cur;
            }
            ans += dis({xb, yb}, {cx, cy}) * cur;
            res = min(res, ans);
        }while(next_permutation(b+1, b+n+1));
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}