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

int n, res;
string a;
vec<int> ke[5005];
map<char, char> op, cl;
stack<char> st;

void dfs(int u, int p = 0){
    if(op.count(a[u])){
        st.push(a[u]);
    }else{
        if(st.empty() or st.top() != cl[a[u]]) return;
        st.pop();
        if(st.empty()) ++res;
    }
    for(int &v : ke[u]) if(v != p){
        dfs(v, u);
    }
    if(op.count(a[u])){
        st.pop();
    }else{
        st.push(cl[a[u]]);
    }
}

inline void LonggVuz(){
    cin >> n >> a;
    a = " " + a;
    fo(i, 2, n){
        int x, y; cin >> x >> y;
        ke[x].pub(y);
        ke[y].pub(x);
    }
    op['('] = ')'; op['['] = ']'; op['{'] = '}';
    cl[')'] = '('; cl[']'] = '['; cl['}'] = '{';
    fo(i, 1, n) dfs(i);
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
