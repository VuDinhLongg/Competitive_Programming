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
#define mxn 100'007

int n, q, p[20][mxn], h[mxn];
vector<int> ke[mxn];

void dfs(int u, int par = 0){
    for(int &v : ke[u]) if(v != par){
        h[v] = h[u] + 1;
        p[0][v] = u;
        for(int k=1; 1<<k <= n; k++) p[k][v] = p[k - 1][p[k - 1][v]];
        dfs(v, u);
    }
}

int lca(int u, int v){
    if(h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];
    fd(i, 19, 0) if(delta >> i & 1){
        u = p[i][u];
    }
    if(u == v) return u;
    fd(i, 19, 0) if(p[i][u] != p[i][v]){
        u = p[i][u];
        v = p[i][v];
    }
    return p[0][u];
}

inline void LonggVuz(){
    cin >> n >> q;
    fo(i, 2, n){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    dfs(1);
    while(q--){
        int x, y, z; cin >> x >> y >> z;
        int t = lca(x, z);
        if(t == x){
            if(lca(y, z) == y and lca(y, x) == t) cout << "YES\n";
            else cout << "NO\n";
        }else if(t == z){
            if(lca(y, x) == y and lca(y, z) == t) cout << "YES\n";
            else cout << "NO\n";
        }else{
            if(lca(y, z) == y and lca(y, x) == t) cout << "YES\n";
            else if(lca(y, x) == y and lca(y, z) == t) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}