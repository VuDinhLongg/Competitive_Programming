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

string k = "Kiaya";
string z = "Zeros";

inline void LonggVuz(){
    int n, x, y, a, b; cin >> n >> x >> y >> a >> b;
    if(a == b){
        if(x + 1 == y){
            out(z);
        }else{
            if(x + a >= y - 1) out(k);
            int d = y - x - 1;
            if(d % (a + 1)) out(k);
            out(z);
        }
    }else if(a > b){
        int d = y - x - 1;
        if(d == 0){
            if(x - (b + 1) >= 1) out(k);
            out(z);
        }
        out(k);
    }else{
        int d = y - x - 1;
        if(d == 0) out(z);
        if(x + a < y - 1) out(z);
        if(y + a + 1 <= n) out(z);
        out(k);
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(1) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}