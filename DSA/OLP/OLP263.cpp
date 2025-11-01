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
#define fo(i, a, b) for(int32_t i=a; i<=b; i++)
#define fd(i, a, b) for(int32_t i=a; i>=b; i--)
#define out(x) return void(cout << (x))
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define dub double
#define int int32_t

const int mod = 1e9 + 7;
const int mxn = 1e6 + 7;

inline string smax(const string &a, const string &b){
    if(len(a) > len(b)) return a;
    if(len(a) < len(b)) return b;
    return max(a, b);
}

string dp[2][1005];

inline void LonggVuz(){
    string a; int m; cin >> a >> m;
    int n = len(a);
    a = " " + a;
    int cur = 0;
    fo(i, 0, m - 1) dp[cur][i] = dp[cur ^ 1][i] = "";
    fo(i, 1, n){
        int d = a[i] - '0';
        int nxt = cur ^ 1;
        fo(j, 0, m - 1) dp[nxt][j] = dp[cur][j];
        fo(j, 0, m - 1) if(dp[cur][j] != "" and dp[cur][j] != "0"){
            int k = (j * 10 + d) % m;
            dp[nxt][k] = smax(dp[nxt][k], dp[cur][j] + string(1, a[i]));
        }
        dp[nxt][d % m] = smax(dp[nxt][d % m], string(1, a[i]));
        cur = nxt;
    }
    cout << (dp[cur][0] != "" ? dp[cur][0] : "!");
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; if(1) cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
