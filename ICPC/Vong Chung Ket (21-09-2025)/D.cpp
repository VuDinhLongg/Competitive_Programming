// LonggVuz
#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<LonggVuz.h>
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
#define float double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e5 + 7;

int n, a[mxn], b[mxn], c, m, res;
vec<int> ke[mxn];
stack<int> st;
bool vis[mxn];

void dfs(int u){
    vis[u] = 1;
    for(int &v : ke[u]){
        if(!vis[v]) dfs(v);
    }
    st.push(u);
}

void cal(int u){
    debug(u);
    vis[u] = 1;
    for(int &v : ke[u]){
        if(!vis[v]) cal(v);
        ++res;
    }
}

void solve(){
    set<int> s;
    s.insert(c);
    fo(i, 1, n) s.insert(a[i]), s.insert(b[i]);
    vec<int> val(all(s));
    c = lower_bound(all(val), c) - begin(val) + 1;
    fo(i, 1, n){
        a[i] = lower_bound(all(val), a[i]) - begin(val) + 1;
        b[i] = lower_bound(all(val), b[i]) - begin(val) + 1;
    }
    fo(i, 1, n) if(a[i] != b[i]){
        ke[b[i]].pub(a[i]);
    }
    fo(i, 1, 1e5) if(!ke[i].empty()) m = i; m = max(m, c);
    debug(c, m);
    fo(i, 1, m) if(i != c and !ke[i].empty()) dfs(i);
    dfs(c);
    fo(i, 1, m) vis[i] = 0;
    while(!st.empty()){
        int u = st.top(); st.pop();
        cal(u);
        while(!st.empty() and vis[st.top()]) st.pop();
        if(!st.empty()) ++res;
        debug(u, res);
    }
    cout << res;
}

void LonggVuz(){
    cin >> n;
    map<int, int> cnta, cntb;
    fo(i, 1, n){
        cin >> a[i];
        ++cnta[a[i]];
        c ^= a[i];
    }
    ++cnta[c];
    fo(i, 1, n){
        cin >> b[i];
        ++cntb[b[i]];
    }
    for(auto &[x, y] : cntb){
        if(y > cnta[x]){
            debug(x);
            out(-1);
        }
    }
    solve();
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
