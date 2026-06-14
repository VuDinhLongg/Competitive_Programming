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

int n, x, b[mxn];

inline void LonggVuz(){
    cin >> n >> x;
    int d1 = 0, d2 = 0, d3 = 0;
    fo(i, 1, n){
        cin >> b[i];
        if(b[i] != -1){
            if(b[i] < x) ++d1;
            else if(b[i] == x) ++d2;
            else ++d3;
        }
    }
    if(d1 >= (n + 1) / 2) out("NO");
    if(d3 >= (n + 1) / 2) out("NO");
    cout << "YES\n";
    fo(i, 1, n){
        if(b[i] == -1) b[i] = x;
        cout << b[i] << ' ';
    }
    el;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(1) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}