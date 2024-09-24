// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Legendary Grandmaster
void End(){
    cerr << "=> Thời gian code chạy: ";
    cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define Sonic() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define ms(a, x) memset(a, x, sizeof(a))
#define bit(n, x) (n >> x & 1)
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int level(string s){
	char c = s[0];
	if(c == '(') return 0;
	if(c == '+' or c == '-') return 1;
	if(c == '*' or c == '/') return 2;
	return 3;
}

int cal(string a){
	int n = len(a);
	stack<int> st;
	for(int i=0; i<n; i++){
		if(a[i] == '('){
			string s = "";
			int j = i + 1;
			while(j < n and isdigit(a[j])){
				s += a[j]; ++j;
			}st.push(stoll(s));
		}else if(a[i] == '+'){
			int x = st.top(); st.pop();
			int y = st.top(); st.pop();
			st.push(x + y);
		}else if(a[i] == '-'){
			int x = st.top(); st.pop();
			int y = st.top(); st.pop();
			st.push(y - x);
		}else if(a[i] == '*'){
			int x = st.top(); st.pop();
			int y = st.top(); st.pop();
			st.push(x * y);
		}else if(a[i] == '/'){
			int x = st.top(); st.pop();
			int y = st.top(); st.pop();
			st.push(y / x);
		}
	}return st.top();
}

void LonggVuz(){
	string a; cin >> a;
	int n = len(a);
	string b = "";
	stack<string> st;
	for(int i=0; i<n; i++){
		if(a[i] == '('){
			st.push(string(1, a[i]));
		}else if(isdigit(a[i])){
			string so = "";
			while(isdigit(a[i])){
				so += a[i];
				++i;
			}--i;
			b += "(" + so + ")";
		}else if(a[i] == ')'){
			while(!st.empty() && st.top() != "("){
				b += st.top();
				st.pop();
			}st.pop();
		}else{
			while(!st.empty() && level(st.top()) >= level(string(1, a[i]))){
				b += st.top();
				st.pop();
			}st.push(string(1, a[i]));
		}
	}
	while(!st.empty()){
		b += st.top();
		st.pop();
	}
	cout << cal(b) << el;
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}