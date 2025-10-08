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

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e5 + 7;

int dp[mxn];
void pre(){
    vec<int> val;
    fo(i, 1, 1e5){
        int x = i, ok = 1;
        while(x){
            if(x % 10 != 1 and x % 10 != 2 and x % 10 != 3){
                ok = 0; break;
            }
            x /= 10;
        }
        if(ok) val.pub(i);
    }
    debug(len(val));
    fo(i, 1, 1e5){
        dp[i] = oo;
        for(int &j : val){
            if(j > i) break;
            if(j == i or dp[i - j] + 1 < dp[i]){
                dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
    }
}

inline void LonggVuz(){
    int n; cin >> n;
    cout << dp[n];
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    pre();
    signed orz = 1; if(1) cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
