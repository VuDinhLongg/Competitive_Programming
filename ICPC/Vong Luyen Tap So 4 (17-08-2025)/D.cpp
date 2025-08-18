// LonggVuz
#include<bits/stdc++.h>
using namespace std;
#define el cout << '\n'
#define inc(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define dec(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int32_t i=a; i<=b; i++)
#define fd(i, a, b) for(int32_t i=a; i>=b; i--)
#define out(x) return void(cout << (x));
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e5 + 7;

#define pe pair<int, int>
#define fi first
#define se second
int n, q, a[mxn], dp[mxn], sz[mxn], par[mxn];
vec<int> ke[mxn];
set<pe> son[mxn];

void dfs(int u, int p = 0){
    dp[u] = a[u];
    sz[u] = 1;
    for(int &v : ke[u]) if(v != p){
        par[v] = u;
        dfs(v, u);
        dp[u] += dp[v];
        sz[u] += sz[v];
        son[u].insert({sz[v], -v});
    }
}

void LonggVuz(){
    cin >> n >> q;
    fo(i, 1, n) cin >> a[i];
    fo(i, 2, n){
        int x, y; cin >> x >> y;
        ke[x].pub(y);
        ke[y].pub(x);
    }
    dfs(1);
    while(q--){
        int t, u; cin >> t >> u;
        if(t == 1){
            cout << dp[u], el;
        }else{
            if(u == 1 or son[u].empty()) continue;
            int p = par[u];
            auto [szv, v] = *son[u].rbegin();
            v = -v;
            // dinh u
            int dpu = dp[u], szu = sz[u];
            dp[u] -= dp[v]; sz[u] -= sz[v]; par[u] = v;
            son[u].erase(--son[u].end());
            // dinh v (con cua u)
            dp[v] = dpu; sz[v] = szu; par[v] = p;
            son[v].insert({sz[u], -u});
            // dinh p (cha cua u)
            son[p].erase(son[p].find({szu, -u}));
            son[p].insert({sz[v], -v});
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; //cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
