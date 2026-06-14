/*======================
   Author : @LonggVuz
======================*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define orz(...) 2005
#endif

#define el cout << '\n'
#define all(x) begin(x), end(x)
#define fix(x) fixed << setprecision(x)
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 167

int n, m, p, a[mxn][mxn][mxn], dp[mxn][mxn][mxn];

inline void LonggVuz(){
    cin >> m >> n >> p;
    fo(i, 1, n) fo(j, 1, m) fo(k, 1, p){
        char c; cin >> c;
        a[i][j][k] = (c == 'N');
    }
    int res = 0;
    // Co dinh chieu i
    memset(dp, 0, sizeof dp);
    fo(i, 1, n) fo(j, 1, m) fo(k, 1, p){
        if(a[i][j][k]){
            dp[i][j][k] = min({dp[i][j - 1][k], dp[i][j][k - 1], dp[i][j - 1][k - 1]}) + 1;
        }
    }
    fo(j, 1, m) fo(k, 1, p){
        vector<int> l(n + 5);
        {
            stack<int> st;
            fo(i, 1, n){
                while(!st.empty() and dp[st.top()][j][k] >= dp[i][j][k]) st.pop();
                l[i] = (st.empty() ? 0 : st.top());
                st.push(i);
            }
        }
        vector<int> r(n + 5);
        {
            stack<int> st;
            fd(i, n, 1){
                while(!st.empty() and dp[st.top()][j][k] >= dp[i][j][k]) st.pop();
                r[i] = (st.empty() ? n + 1 : st.top());
                st.push(i);
            }
        }
        fo(i, 1, n){
            int le = l[i] + 1;
            int ri = r[i] - 1;
            maxi(res, dp[i][j][k] * (ri - le + 1));
        }
    }
    // Co dinh chieu j
    memset(dp, 0, sizeof dp);
    fo(j, 1, m) fo(i, 1, n) fo(k, 1, p){
        if(a[i][j][k]){
            dp[j][i][k] = min({dp[j][i - 1][k], dp[j][i][k - 1], dp[j][i - 1][k - 1]}) + 1;
        }
    }
    fo(i, 1, n) fo(k, 1, p){
        vector<int> l(m + 5);
        {
            stack<int> st;
            fo(j, 1, m){
                while(!st.empty() and dp[st.top()][i][k] >= dp[j][i][k]) st.pop();
                l[j] = (st.empty() ? 0 : st.top());
                st.push(j);
            }
        }
        vector<int> r(m + 5);
        {
            stack<int> st;
            fd(j, m, 1){
                while(!st.empty() and dp[st.top()][i][k] >= dp[j][i][k]) st.pop();
                r[j] = (st.empty() ? m + 1 : st.top());
                st.push(j);
            }
        }
        fo(j, 1, m){
            int le = l[j] + 1;
            int ri = r[j] - 1;
            maxi(res, dp[j][i][k] * (ri - le + 1));
        }
    }
    // Co dinh chieu k
    memset(dp, 0, sizeof dp);
    fo(k, 1, p) fo(i, 1, n) fo(j, 1, m){
        if(a[i][j][k]){
            dp[k][i][j] = min({dp[k][i - 1][j], dp[k][i][j - 1], dp[k][i - 1][j - 1]}) + 1;
        }
    }
    fo(i, 1, n) fo(j, 1, m){
        vector<int> l(p + 5);
        {
            stack<int> st;
            fo(k, 1, p){
                while(!st.empty() and dp[st.top()][i][j] >= dp[k][i][j]) st.pop();
                l[k] = (st.empty() ? 0 : st.top());
                st.push(k);
            }
        }
        vector<int> r(p + 5);
        {
            stack<int> st;
            fd(k, p, 1){
                while(!st.empty() and dp[st.top()][i][j] >= dp[k][i][j]) st.pop();
                r[k] = (st.empty() ? p + 1 : st.top());
                st.push(k);
            }
        }
        fo(k, 1, p){
            int le = l[k] + 1;
            int ri = r[k] - 1;
            maxi(res, dp[k][i][j] * (ri - le + 1));
        }
    }
    cout << res * 4;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}