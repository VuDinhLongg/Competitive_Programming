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
#define mxn 200'007

int n, m, q, v[mxn], h[mxn];
int f[mxn], l[mxn], r[mxn];
int dpl[mxn], dpr[mxn];

inline void LonggVuz(){
    cin >> n >> m; --m;
    v[0] = 0;
    v[n + 1] = m + 1;
    fo(i, 1, n) cin >> v[i];
    fo(i, 1, n) cin >> h[i];
    fo(i, 1, n) f[i] = f[i - 1] + h[i];
    {
    	stack<int> st;
    	fo(i, 1, n){
    		while(st.size() and h[st.top()] < h[i]) st.pop();
    		l[i] = (st.size() ? st.top() : 0);
    		st.push(i);
    	}
    }
    {
    	stack<int> st;
    	fd(i, n, 1){
    		while(st.size() and h[st.top()] < h[i]) st.pop();
    		r[i] = (st.size() ? st.top() : n + 1);
    		st.push(i);
    	}
    }
    fo(i, 1, n){
    	int j = l[i];
    	int add = h[i] * (v[i] - v[j] - 1) - (f[i - 1] - f[j]);
    	dpl[i] = dpl[j] + add;
    }
    fd(i, n, 1){
    	int j = r[i];
    	int add = h[i] * (v[j] - v[i] - 1) - (f[j - 1] - f[i]);
    	dpr[i] = dpr[j] + add;
    }
    cin >> q;
    while(q--){
    	int k; cin >> k;
    	int res = 0;
    	{
    		int l = 0, r = n + 1;
    		while(r - l > 1){
    			int mid = l + r >> 1;
    			if(k > dpl[mid]) l = mid;
    			else r = mid;
    		}
    		res += l;
    	}
    	{
    		int l = 0, r = n + 1;
    		while(r - l > 1){
    			int mid = l + r >> 1;
    			if(k > dpr[mid]) r = mid;
    			else l = mid;
    		}
    		res += n - r + 1;
    	}
    	mini(res, n);
    	cout << res, el;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
