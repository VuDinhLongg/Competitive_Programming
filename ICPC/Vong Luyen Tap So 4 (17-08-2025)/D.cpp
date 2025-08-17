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
int n, q, a[mxn], dp[mxn], sz[mxn], par[mxn], son[mxn];
vec<int> ke[mxn], pos[mxn];

void dfs(int u, int p = 0){
    dp[u] = a[u];
    sz[u] = 1;
    for(int &v : ke[u]) if(v != p){
        par[v] = u;
        dfs(v, u);
        dp[u] += dp[v];
        sz[u] += sz[v];
        if(sz[v] > sz[son[u]]){
            son[u] = v;
        }else if(sz[v] == sz[son[u]] and v < son[u]){
            son[u] = v;
        }
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
            // cout << par[u] << ' ' << son[u] << ' ';
            cout << dp[u], el;
        }else{
            if(par[u] == 0 or son[u] == 0) continue;
            int s = son[u], p = par[u];
            // dinh u
            int dpu = dp[u], szu = sz[u];
            ke[u].erase(find(all(ke[u]), p));
            dp[u] -= dp[s]; sz[u] -= sz[s]; par[u] = s; son[u] = 0;
            for(int &v : ke[u]) if(v != par[u]){
                if(sz[v] > sz[son[u]]) son[u] = v;
                else if(sz[v] == sz[son[u]] and v < son[u]) son[u] = v;
            }
            // con cua u
            ke[s].pub(p);
            dp[s] = dpu; sz[s] = szu; par[s] = p;
            if(sz[u] > sz[son[s]]) son[s] = u;
            else if(sz[u] == sz[son[s]] and u < son[s]) son[s] = u;
            son[p] = 0;
            // cha cua u
            ke[p].erase(find(all(ke[p]), u));
            ke[p].pub(s);
            for(int &v : ke[p]) if(v != par[p]){
                if(sz[v] > sz[son[p]]) son[p] = v;
                else if(sz[v] == sz[son[p]] and v < son[p]) son[p] = v;
            }
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
