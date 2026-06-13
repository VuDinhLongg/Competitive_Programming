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
#define mxn 500'007

int n, a[mxn], posl[mxn], posr[mxn], dpl[mxn], dpr[mxn];

inline void LonggVuz(){
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    {
    	stack<int> st;
    	fo(i, 1, n){
    		while(st.size() and a[st.top()] >= a[i]) st.pop();
    		posl[i] = (st.size() ? st.top() : 0);
    		st.push(i);
    	}
    	fo(i, 1, n){
    		int j = posl[i];
    		dpl[i] = dpl[j] + a[i] * (i - j);
    	}
    }
    {
    	stack<int> st;
    	fd(i, n, 1){
    		while(st.size() and a[st.top()] >= a[i]) st.pop();
    		posr[i] = (st.size() ? st.top() : n + 1);
    		st.push(i);
    	}
    	fd(i, n, 1){
    		int j = posr[i];
    		dpr[i] = dpr[j] + a[i] * (j - i);
    	}
    }
    int res = -1e18;
    fo(i, 1, n){
    	int ans = dpl[i] + dpr[i] - a[i];
    	maxi(res, ans);
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
