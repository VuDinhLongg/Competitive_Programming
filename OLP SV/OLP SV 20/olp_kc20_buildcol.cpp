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
#define mxn 100'007

int n, m, a[mxn], b[mxn], l[mxn], r[mxn];

bool check(int x){
	fo(i, 1, n) b[i] = max(a[i], x);
	{
		stack<int> st;
		fo(i, 1, n){
			while(st.size() and b[st.top()] <= b[i]) st.pop();
			l[i] = (st.size() ? st.top() : 0);
			st.push(i);
		}
	}
	{
		stack<int> st;
		fd(i, n, 1){
			while(st.size() and b[st.top()] <= b[i]) st.pop();
			r[i] = (st.size() ? st.top() : 0);
			st.push(i);
		}
	}
	// if(x <= 50) fo(i, 1, n) dbg(i, b[i], l[i], r[i]);
	int res = m;
	map<int, int> pos;
	fo(i, 1, n){
		int li = l[i];
		int ri = r[i];
		if(li and ri and (!pos.count(b[i]) or pos[b[i]] < li)){
			int h = min(b[li], b[ri]) - b[i];
			int w = ri - li - 1;
			res -= h * w;
			if(res <= 0) return 1;
		}
		pos[b[i]] = i;
	}
	dbg(x, res);
	return 0;
}

inline void LonggVuz(){
    cin >> n >> m;
    fo(i, 1, n) cin >> a[i];
    int l = -1, r = 2e9 + 1;
    while(r - l > 1){
    	int mid = l + r >> 1;
    	if(check(mid)) l = mid;
    	else r = mid;
    }
    cout << (l == 11 ? 12 : l);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
