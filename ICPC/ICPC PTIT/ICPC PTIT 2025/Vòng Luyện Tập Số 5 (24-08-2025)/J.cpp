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

#define ii pair<int, int>
#define ip pair<int, ii>
#define pi pair<ii, int>
#define pp pair<ii, ii>
#define fi first
#define se second
int n, m, st, en, dp[mxn];
vec<ip> ke[mxn];

void LonggVuz(){
    cin >> n >> m >> st >> en;
    fo(i, 1, m){
        int x, y, t, k; cin >> x >> y >> t >> k;
        ke[x].pub({y, {t, k}});
        ke[y].pub({x, {t, k}});
    }
    fo(i, 1, n) dp[i] = oo;
    dp[st] = 0;
    priority_queue<ip, vec<ip>, greater<ip>> q;
    q.push({0, {0, st}});
    while(!q.empty()){
        auto [cur, tmp] = q.top(); q.pop();
        auto [tg, u] = tmp;
        if(cur > dp[u]) continue;
        for(auto &[v, p] : ke[u]){
            auto [t, k] = p;
            int gan = (tg / k + (tg % k > 0)) * k;
            int d = gan - tg + t;
            if(dp[u] + d < dp[v]){
                dp[v] = dp[u] + d;
                q.push({dp[v], {gan + t, v}});
            }
        }
    }
    // fo(i, 1, n) cout << dp[i], el;
    cout << (dp[en] < oo ? dp[en] : -1);
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
