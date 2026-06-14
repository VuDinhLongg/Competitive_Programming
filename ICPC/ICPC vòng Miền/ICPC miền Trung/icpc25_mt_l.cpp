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

int n, m, vt, s, t, dp[mxn];
vector<pii> ke[mxn];

inline void LonggVuz(){
    cin >> n >> m >> vt;
    fo(i, 1, m){
        int x, y, w; cin >> x >> y >> w;
        ke[x].push_back({y, w});
        ke[y].push_back({x, w});
    }
    cin >> s >> t;
    fo(i, 1, n) dp[i] = 1e18;
    dp[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({dp[s], s});
    while(!q.empty()){
        auto [cur, u] = q.top(); q.pop();
        if(cur > dp[u]) continue;
        if(u == t) break;
		int p = 0;
		if(u != s) p = max(p, (int)ke[u].size() - 2);
        for(auto &[v, w] : ke[u]){
            int c = p * vt + w;
            if(dp[u] + c < dp[v]){
                dp[v] = dp[u] + c;
                q.push({dp[v], v});
            }
        }
    }
    double res = (double)1.0 * dp[t] / vt;
    cout << fix(6) << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}