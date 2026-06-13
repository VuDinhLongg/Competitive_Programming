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
const int mxn = 1e6 + 7;

#define pe pair<int, int>
#define fi first
#define se second

void LonggVuz(){
    int n; cin >> n;
    int a[n+5];
    fo(i, 1, n) cin >> a[i];
    set<pe> s;
    vec<int> val(n + 1), pre(n + 1), nxt(n + 1), del(n + 1);
    fo(i, 2, n - 1){
        val[i] = min(a[i - 1], a[i + 1]);
        pre[i] = i - 1;
        nxt[i] = i + 1; 
        if(val[i] >= a[i]) s.insert({a[i], i});
    }
    int res = 0;
    while(!s.empty()){
        auto it = s.begin();
        auto [ans, i] = *it; s.erase(it);
        // cout << val[i] << ' ' << i, el;
        res += val[i]; del[i] = 1;
        int trc = pre[i], sau = nxt[i];
        int vtrc = val[trc], vsau = val[sau];
        if(1 < trc){
            val[trc] = min(a[pre[trc]], a[sau]);
            if(val[trc] >= a[trc] and !s.count({a[trc], trc})){
                s.insert({a[trc], trc});
            }
            nxt[trc] = sau;
        }
        if(sau < n){
            val[sau] = min(a[nxt[sau]], a[trc]);
            if(val[sau] >= a[sau] and !s.count({a[sau], sau})){
                s.insert({a[sau], sau});
            }
            pre[sau] = trc;
        }
    }
    fo(i, 2, n - 1) if(!del[i]){
        s.insert({val[i], i});
    }
    while(!s.empty()){
        auto it = s.end(); --it;
        auto [ans, i] = *it; s.erase(it);
        // cout << ans << ' ' << i, el;
        res += ans;
        int trc = pre[i], sau = nxt[i];
        int vtrc = val[trc], vsau = val[sau];
        if(1 < trc){
            val[trc] = min(a[pre[trc]], a[sau]);
            nxt[trc] = sau;
        }
        if(sau < n){
            val[sau] = min(a[nxt[sau]], a[trc]);
            pre[sau] = trc;
        }
    }
    cout << res;
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
