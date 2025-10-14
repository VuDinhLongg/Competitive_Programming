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
#define pii pair<int, int>
#define pip pair<int, pii>
#define ppi pair<pii, int>
#define fi first
#define se second

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e5 + 7;

int uoc[mxn * 10];
void sang(){
    fo(i, 2, 1e6) if(uoc[i] == 0){
        inc(j, i, 1e6, i) if(uoc[j] == 0){
            uoc[j] = i;
        }
    }
}

inline int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int n, s[mxn], c[mxn];
int dp[mxn][3], up[mxn], ans[mxn];
vec<pii> canh;
vec<int> ke[mxn];

void dfs1(int u, int p = 0){
    for(int &v : ke[u]) if(v != p){
        dfs1(v, u);
        fo(i, 0, 0){
            if(dp[v][i] + s[u] > dp[u][0]){
                dp[u][2] = dp[u][1];
                dp[u][1] = dp[u][0];
                dp[u][0] = dp[v][i] + s[u];
            }else if(dp[v][i] + s[u] > dp[u][1]){
                dp[u][2] = dp[u][1];
                dp[u][1] = dp[v][i] + s[u];
            }else if(dp[v][i] + s[u] > dp[u][2]){
                dp[u][2] = dp[v][i] + s[u];
            }
        }
    }
    if(s[u] > dp[u][0]){
        dp[u][2] = dp[u][1];
        dp[u][1] = dp[u][0];
        dp[u][0] = s[u];
    }else if(s[u] > dp[u][1]){
        dp[u][2] = dp[u][1];
        dp[u][1] = s[u];
    }else if(s[u] > dp[u][2]){
        dp[u][2] = s[u];
    }
}

void dfs2(int u, int p = 0){
    for(int &v : ke[u]) if(v != p){
        up[v] = up[u] + s[v];
        if(dp[v][0] + s[u] == dp[u][0]){
            up[v] = max(up[v], dp[u][1] + s[v]);
        }else{
            up[v] = max(up[v], dp[u][0] + s[v]);
        }
        dfs2(v, u);
    }
}

int solve(int p){
    fo(u, 1, n){
        dp[u][0] = dp[u][1] = dp[u][2] = -oo;
        up[u] = -oo;
        ans[u] = -oo;
        ke[u].clear();
    }
    for(auto &[x, y] : canh){
        if(gcd(c[x], c[y]) % p == 0){
            ke[x].pub(y);
            ke[y].pub(x);
        }
    }
    fo(u, 1, n) if(dp[u][0] == -oo){
        dfs1(u);
    }
    fo(u, 1, n) if(up[u] == -oo){
        up[u] = s[u];
        dfs2(u);
    }
    fo(u, 1, n) debug(u, dp[u][0], dp[u][1], dp[u][2], up[u]);
    int res = -oo;
    fo(u, 1, n){
        ans[u] = -oo;
        if(dp[u][0] > -oo and dp[u][1] > -oo and dp[u][2] > -oo)
            ans[u] = max(ans[u], dp[u][0] + dp[u][1] + dp[u][2]);
        if(dp[u][0] > -oo and dp[u][1] > -oo and up[u] > -oo and up[u] != dp[u][0] and up[u] != dp[u][1])
            ans[u] = max(ans[u], dp[u][0] + dp[u][1] + up[u]);
        if(ans[u] == -oo) continue;
        ans[u] = ans[u] * 2 - s[u] * 3;
        debug(u, ans[u]);
        res = max(res, ans[u]);
    }
    return res;
}

inline void LonggVuz(){
    sang();
    cin >> n;
    fo(i, 1, n) cin >> s[i];
    fo(i, 1, n) cin >> c[i];
    fo(i, 2, n){
        int x, y; cin >> x >> y;
        canh.pub({x, y});
    }
    set<int> se;
    fo(i, 1, n){
        int tmp = c[i];
        while(tmp > 1){
            se.insert(uoc[tmp]);
            tmp /= uoc[tmp];
        }
    }
    int res = -oo;
    for(int p : se) res = max(res, solve(p));
    if(res > -oo) cout << res;
    else cout << "No Solution";
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
