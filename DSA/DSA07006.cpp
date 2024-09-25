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
#define pb push_back
#define is insert
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

string a;
int n, m[205], del[205];
set<string> se;

void run(int id, int pos){
	if(id){
		string s = "";
		for(int i=0; i<n; i++){
			if(!del[i]) s += a[i];
		}se.insert(s);
	}
	for(int i=pos; i<n; i++){
		if(a[i] == '('){
			if(!del[i]){
				del[i] = del[m[i]] = 1;
				run(id + 1, i + 1);
				del[i] = del[m[i]] = 0;
			}
		}
	}
}

void LonggVuz(){
	ms(m, 0);
	se.clear();
	cin >> a; n = len(a);
	stack<int> st;
	for(int i=0; i<n; i++){
		if(a[i] == '('){
			st.push(i);
		}else if(a[i] == ')'){
			m[st.top()] = i;
			st.pop();
		}
	}
	run(0, 0);
	for(auto &i : se){
		cout << i << el;
	}
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}