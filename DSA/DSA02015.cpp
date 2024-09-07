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
#define ms(x) memset(x, 0, sizeof(x))
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

set<str> se;
int max_len;

bool check(str a, int n){
	if(n < 2) return 0;
	stack<char> st;
	for(int i=0; i<n; i++){
		if(a[i] == '('){
			st.push(a[i]);
		}else if(a[i] == ')'){
			if(!st.empty()){
				st.pop();
			}else return 0;
		}
	}return st.empty();
}

void run(str a, int pos){
	int n = len(a);
	if(n < max_len) return;
	if(check(a, n)){
		if(n > max_len){
			se.clear();
			se.insert(a);
			max_len = n;
		}else if(n == max_len) se.insert(a);
		return;
	}
	for(int i=pos; i<n; i++){
		if(a[i] == '(' || a[i] == ')'){
			str b = a;
			b.erase(b.begin() + i);
			run(b, i);
		}
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		se.clear(); max_len = 0;
		str a; cin >> a;
		run(a, 0);
		if(!se.empty()){
			for(auto &i : se){
				cout << i << ' ';
			}cout << el;
		}else cout << "-1\n";
	}
	
	End();
}