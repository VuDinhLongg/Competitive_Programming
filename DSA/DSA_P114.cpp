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



void LonggVuz(){
    int n; cin >> n;
    int a[n+5];
    fo(i, 1, n) cin >> a[i];
    vec<int> l(n + 1);
    {
        stack<int> st;
        fo(i, 1, n){
            while(!st.empty() and a[st.top()] <= a[i]) st.pop();
            if(st.empty()) l[i] = 0;
            else l[i] = st.top();
            st.push(i);
        }
    }
    vec<int> r(n + 1);
    {
        stack<int> st;
        fd(i, n, 1){
            while(!st.empty() and a[st.top()] < a[i]) st.pop();
            if(st.empty()) r[i] = n + 1;
            else r[i] = st.top();
            st.push(i);
        }
    }
    int res = 0;
    fo(i, 1, n){
        int le = l[i] + 1, ri = r[i] - 1;
        res += a[i] * (i - le + 1) * (ri - i + 1);
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
