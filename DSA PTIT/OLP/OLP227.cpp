// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
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
const int mxn = 1e6 + 7;

int n, k, w[mxn], sum[mxn];
int aim, dp[mxn], mark[mxn];
vec<int> ke[mxn];

void dfs(int u, int p = 0){
    sum[u] = w[u];
    for(int &v : ke[u]) if(v != p){
        dfs(v, u);
        sum[u] += sum[v];
    }
}

void run(int u, int p = 0){
    dp[u] = w[u];
    for(int &v : ke[u]) if(v != p){
        if(sum[v] >= aim) run(v, u);
        else dp[v] = sum[v];
        if(!mark[v]) dp[u] += dp[v];
    }
    if(dp[u] >= aim) mark[u] = 1;
}

bool check(int m){
    aim = m;
    fo(i, 1, n) dp[i] = mark[i] = 0;
    run(1);
    int cnt = 0;
    fo(i, 1, n) cnt += mark[i];
    return cnt >= k;
}

inline void LonggVuz(){
    cin >> n >> k;
    fo(i, 1, n) cin >> w[i];
    fo(i, 2, n){
        int x, y; cin >> x >> y;
        ke[x].pub(y);
        ke[y].pub(x);
    }
    dfs(1);
    int l = 0, r = 1e12 + 1;
    while(r - l > 1){
        int m = l + r >> 1;
        if(check(m)) l = m;
        else r = m;
    }
    cout << l;
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
