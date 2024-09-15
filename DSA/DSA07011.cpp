// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Noob C++
void End(){
    cerr << "=> Thời gian code chạy: ";
    cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define Sonic() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define ms(x) memset(x, 0, sizeof(x))
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define str string
#define int int64_t
#define ld long double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;



void LonggVuz(){
	str a; cin >> a;
	int n = len(a);
	stack<str> st;
	for(int i=0; i<n; i++){
		if(a[i] >= 'A' && a[i] <= 'Z'){
			st.push(string(1, a[i]));
		}else{
			str x = st.top(); st.pop();
			str y = st.top(); st.pop();
			str s = string(1, a[i]) + y + x;
			st.push(s);
		}
	}cout << st.top() << el;
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}