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
#define int int32_t
#define ld long double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int level(char c){
	if(c == '(') return 0;
	else if(c == '-' || c == '+') return 1;
	else if(c == '*' || c == '/') return 2;
	return 3;
}

void LonggVuz(){
	str a; cin >> a;
	int n = len(a);
	stack<char> st;
	str res = "";
	for(int i=0; i<n; i++){
		if(isalpha(a[i])){
			res.pb(a[i]);
		}else{
			if(a[i] == '('){
				st.push(a[i]);
			}else if(a[i] == ')'){
				while(!st.empty() && st.top() != '('){
					res.pb(st.top()); st.pop();
				}st.pop();
			}else{
				while(!st.empty() && level(st.top()) >= level(a[i])){
					res.pb(st.top()); st.pop();
				}st.push(a[i]);
			}
		}
	}
	while(!st.empty()){
		res.pb(st.top()); st.pop();
	}cout << res << el;
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}