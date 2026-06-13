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

int f[1001];
void pre(){
    int n = 1e3;
    fo(i, 2, n) f[i] = oo;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int x = q.front(); q.pop();
        if(x == n) continue;
        fo(i, 1, x) if(x + x / i <= n){
            int y = x + x / i;
            if(f[x] + 1 < f[y]){
                f[y] = f[x] + 1;
                q.push(y);
            }
        }
    }
    // fo(i, 1, n) cout << f[i], el;
}

void LonggVuz(){
    int n, k; cin >> n >> k;
    int b[n+5], c[n+5];
    fo(i, 1, n) cin >> b[i];
    fo(i, 1, n) cin >> c[i];
    int sum = 0;
    fo(i, 1, n){
        sum += f[b[i]];
    }
    if(sum <= k){
        int res = 0;
        fo(i, 1, n) res += c[i];
        out(res);
    }
    vec<int> dp(k + 5);
    int cur = 0;
    fo(i, 1, n){
        int x = f[b[i]];
        fd(j, k, x) if(dp[j - x] + c[i] > dp[j]){
            dp[j] = dp[j - x] + c[i];
        }
    }
    int res = 0;
    fo(i, 0, k) res = max(res, dp[i]);
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    pre();
    signed orz = 1; cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
