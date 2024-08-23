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
#define db double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

bool dau(char c){
	return c == '+' || c == '-' || c == '*' || c == '/';
}

void solve(str a, int n){
	stack<char> st;
	stack<str> xau;
	str s = "";
	bool ok = 0;
	for(int i=0; i<n; i++){
		if(a[i] == '('){
			xau.push("");
			st.push(a[i]);
		}else if(a[i] == ')'){
			if(!st.empty()){
				if(xau.top() != ""){
					st.pop(); xau.pop();
				}else{
					ok = 1; break;
				}
			}else{
				ok = 1; break;
			}
		}else{
			if(dau(a[i]) && !xau.empty()) xau.top().pb(a[i]);
		}
	}if(ok){
		cout << "Yes\n";
	}else cout << "No\n";
}

signed main(){
	LonggVuz();
	
	tc(){
		str a; getline(cin >> ws, a);
		solve(a, len(a));
	}
	
	End();
}