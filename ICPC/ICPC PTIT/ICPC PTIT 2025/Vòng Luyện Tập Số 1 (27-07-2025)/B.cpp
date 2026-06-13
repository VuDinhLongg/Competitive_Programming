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
#define pb push_back
#define po pop_back
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 8;
const int mxn = 1e6 + 9;

struct trie{
    vec<vec<int>> c;
    vec<int> e;
    int cnt;
    trie(int n){
        c.resize(n + 5, vec<int>(26)); e.resize(n + 5); cnt = 0;
    }
    void add(string &s){
        int u = 0;
        for(char &i : s){
            int k = i - 'a';
            if(c[u][k] == 0) c[u][k] = ++cnt;
            u = c[u][k];
        }
        ++e[u];
    }
    void dfs(int u){
        fo(k, 0, 25) if(c[u][k]){
            int v = c[u][k];
            dfs(v);
        }
    }
};

void LonggVuz(){
    string s; cin >> s;
    int n = len(s);
    s.insert(begin(s), ' ');
    trie t(1e6);
    int k; cin >> k;
    fo(i, 1, k){
        string a; cin >> a;
        reverse(all(a));
        t.add(a);
    }
    vec<int> dp(n + 1);
    dp[0] = 1;
    fo(i, 1, n){
        int u = 0;
        fd(j, i, 1){
            int v = s[j] - 'a';
            if(t.c[u][v] == 0) break;
            u = t.c[u][v];
            if(t.e[u]){
                dp[i] += dp[j - 1];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[n];
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int o = 1; //cin >> o;
    while(o){
        LonggVuz();
        if(--o) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
    return (0 ^ 0);
}
