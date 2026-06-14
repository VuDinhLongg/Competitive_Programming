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
#define mxn 300'007

int n, a[mxn];

inline void LonggVuz(){
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    int res = 0, i = 1;
    while(i <= n){
        int j = i;
        while(j <= n and a[j] == a[i]) ++j;
        if(a[i] > 0){
            int len = j - i;
            if(len >= 3) res += len * (len - 1) * (len - 2) / 6;
            if(len >= 2) res += len * (len - 1) / 2 * (j - len - 1);
        }
        i = j;
    }
    cout << res, el;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(1) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}