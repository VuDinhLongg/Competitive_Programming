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

stack<int> st;

void LonggVuz(){
	string a; cin >> a;
	if(a == "PUSH"){
		int x; cin >> x;
		st.push(x);
	}else if(a == "POP"){
		if(!st.empty()) st.pop();
	}else{
		if(!st.empty()){
			cout << st.top() << el;
		}else cout << "NONE\n";
	}
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
