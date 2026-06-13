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

#define pe pair<int, int>
#define fi first
#define se second

void LonggVuz(){
    int k; cin >> k;
    vec<int> dp(k, oo);
    priority_queue<pe, vec<pe>, greater<pe>> q;
    q.push({0, 0});
    while(!q.empty()){
        auto [cur, u] = q.top(); q.pop();
        if(cur > dp[u]) continue;
        fo(v, 0, 9) if(!(u == 0 and v == 0)){
            int x = (u * 10 + v) % k;
            if(cur + v < dp[x]){
                dp[x] = cur + v;
                q.push({dp[x], x});
            }
        }
    }
    cout << dp[0];
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; //cin >> orz;
    while(orz--){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
