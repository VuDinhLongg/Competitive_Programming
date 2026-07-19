/*======================
   Author : @LonggVuz
======================*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define yay(...) 2005
#endif

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 1'000'007

int n, m, a[16], res;
stack<int> st;

void backtrack(int idx){
	if(idx > n){
		int sum = 0;
		stack<int> st2 = st;
		while(len(st2)){
			sum += st2.top();
			st2.pop();
		}
		if(sum % m == 0) ++res;
		return;
	}
	st.push(a[idx]);
	backtrack(idx + 1);
	st.pop();
	st.push(-a[idx]);
	backtrack(idx + 1);
	st.pop();
	if(idx > 1 and st.top() <= 1e18 / a[idx]){
		int pre = st.top();
		st.top() *= a[idx];
		backtrack(idx + 1);
		st.top() = pre;
	}
}

inline void LonggVuz(){
	while(len(st)) st.pop();
	cin >> n >> m;
	fo(i, 1, n) cin >> a[i];
	res = 0;
	backtrack(1);
	cout << res / 2, el;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(1) cin >> o_o;
	fo(c_c, 1, o_o) yay(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
