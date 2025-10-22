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

#define pii pair<int, int>
#define pip pair<int, pii>
#define ppi pair<pii, int>
#define fi first
#define se second

int n, sz[mxn], dp[mxn], cnt[mxn];
vec<pii> ke[mxn];

int check(int w){
    while(w){
        if(w % 10 != 4 and w % 10 != 7) return 0;
        w /= 10;
    }
    return 1;
}

void dfs(int u, int p = 0){
    sz[u] = 1;
    for(auto &[v, w] : ke[u]) if(v != p){
        dfs(v, u);
        if(w) dp[u] += sz[v];
        else dp[u] += dp[v];
        sz[u] += sz[v];
    }
}

void cal(int u, int p = 0){
    for(auto &[v, w] : ke[u]) if(v != p){
        if(w) dp[v] += n - sz[v];
        else dp[v] = dp[u];
        cal(v, u);
    }
}

inline void LonggVuz(){
    cin >> n;
    fo(i, 2, n){
        int x, y, w; cin >> x >> y >> w;
        w = check(w);
        ke[x].pub({y, w});
        ke[y].pub({x, w});
    }
    dfs(1);
    cal(1);
    int res = 0;
    fo(i, 1, n) res += dp[i] * (dp[i] - 1);
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
