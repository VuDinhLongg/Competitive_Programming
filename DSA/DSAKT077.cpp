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

const int mod = 1e9 + 7;
const int mxn = 5e3 + 7;

int m, n, child[mxn][26], e[mxn], cnt;
int sz[mxn], dp[mxn];
char a[10][10];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool vis[10][10];
set<string> res;

void add(string &s){
    int u = 0;
    for(char &c : s){
        int k = c - 'a';
        if(child[u][k] == 0) child[u][k] = ++cnt;
        u = child[u][k];
    }
    ++e[u];
}

void dfs(int u){
    sz[u] = e[u];
    fo(k, 0, 25) if(child[u][k]){
        dfs(child[u][k]);
        sz[u] += sz[child[u][k]];
    }
}

void run(int i, int j, int u, string &w){
    // cout << w, el;
    vis[i][j] = 1;
    w.pub(a[i][j]);
    if(a[i][j] == 'q') w.pub('u');
    if(e[u]){
        res.insert(w);
        dp[u] += e[u];
    }
    if(len(w) > 25) return;
    fo(id, 0, 7){
        int ii = i + dx[id];
        int jj = j + dy[id];
        if(1 <= ii and ii <= n and 1 <= jj and jj <= n){
            if(!vis[ii][jj]){
                int k = a[ii][jj] - 'a';
                if(child[u][k]){
                    if(a[ii][jj] == 'q'){
                        int uu = child[u][k];
                        if(child[uu]['u' - 'a'] and dp[uu] < sz[uu]){
                            run(ii, jj, child[uu]['u' - 'a'], w);
                            dp[uu] += dp[child[uu]['u' - 'a']];
                            dp[u] += dp[uu];
                        }
                    }else{
                        if(dp[u] < sz[u]){
                            run(ii, jj, child[u][k], w);
                            dp[u] += dp[child[u][k]];
                        }
                    }
                }
            }
        }
    }
    vis[i][j] = 0;
    w.pob();
    if(w.back() == 'q') w.pob();
}

void LonggVuz(){
    cin >> m;
    fo(i, 1, m){
        string s; cin >> s;
        add(s);
    }
    dfs(0);
    while(cin >> n){
        if(n == 0) break;
        fo(i, 1, n) fo(j, 1, n){
            cin >> a[i][j];
        }
        res.clear();
        fo(i, 0, cnt) dp[i] = 0;
        fo(i, 1, n) fo(j, 1, n) if(dp[0] < sz[0]){
            int k = a[i][j] - 'a';
            if(child[0][k]){
                string w = "";
                if(a[i][j] == 'q'){
                    int u = child[0][k];
                    if(child[u]['u' - 'a'] and dp[u] < sz[u]){
                        run(i, j, child[u]['u' - 'a'], w);
                        dp[u] += dp[child[u]['u' - 'a']];
                        dp[0] += dp[u];
                    }
                }else if(dp[child[0][k]] < sz[child[0][k]]){
                    run(i, j, child[0][k], w);
                    dp[0] += dp[child[0][k]];
                }
            }
        }
        for(auto &i : res) cout << i, el; cout << "-\n";
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
