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

int n, m, a[1001][1001], dp[1001][1001];

void LonggVuz(){
    cin >> n >> m;
    fo(i, 1, n) fo(j, 1, m){
        cin >> a[i][j];
        if(a[i][j]) dp[i][j] = dp[i - 1][j] + 1;
    }
    int res = 0;
    fo(i, 1, n){
        vec<int> l(m + 1), r(m + 1);
        {
            stack<int> st;
            fo(j, 1, m){
                while(!st.empty() and dp[i][st.top()] >= dp[i][j]) st.pop();
                if(st.empty()) l[j] = 0;
                else l[j] = st.top();
                st.push(j);
            }
        }
        {
            stack<int> st;
            fd(j, m, 1){
                while(!st.empty() and dp[i][st.top()] >= dp[i][j]) st.pop();
                if(st.empty()) r[j] = m + 1;
                else r[j] = st.top();
                st.push(j);
            }
        }
        fo(j, 1, m) res = max(res, min(dp[i][j], r[j] - l[j] - 1));
    }
    cout << res;
    fo(i, 1, n) fo(j, 1, m) dp[i][j] = 0;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int o = 1; cin >> o;
    while(o){
        LonggVuz();
        if(--o) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
    return (0 ^ 0);
}
