// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Noob C++
void End(){
    cerr << "=> Thời gian code chạy: ";
    cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define LonggVuz() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define ms(a, x) memset(a, x, sizeof(a))
#define tc() int TC; cin >> TC; while(TC--)
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define str string
#define int intmax_t
#define ld long double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

bool cs(char c){
	return c >= '0' && c <= '9';
}

void solve(str a, int n){
	stack<char> st;
	for(int i=0; i<n; i++){
		if(a[i] != ']') st.push(a[i]);
		else{
			str tmp = "";
			while(!st.empty() && st.top() != '['){
				tmp.pb(st.top()); st.pop();
			}reverse(all(tmp)); st.pop();
			str so = "";
			while(!st.empty() && cs(st.top())){
				so.pb(st.top()); st.pop();
			}reverse(all(so));
			int x = 1;
			if(len(so)) x = stoll(so);
			str s = "";
			while(x--) s += tmp;
			for(char &c : s) st.push(c);
		}
	}str res = "";
	while(!st.empty()){
		res.pb(st.top()); st.pop();
	}reverse(all(res));
	cout << res << el;
}

signed main(){
	LonggVuz();
	
	tc(){
		str a; cin >> a;
		solve(a, len(a));
	}
	
	End();
}