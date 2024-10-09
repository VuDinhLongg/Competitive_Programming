// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Legendary Grandmaster
void End(){
    cerr << "=> Smoothly Finished! Time taken: ";
    cerr << (0.001 * clock()) << "s" << string(25, '\t');
}
#define Sonic() cin.tie(NULL) -> sync_with_stdio(false);
#define fix(x) fixed << setprecision(x)
#define all(x) begin(x), end(x)
#define len(x) (int)x.size()
#define gel(x) getline(cin >> ws, x)
#define ms(a, x) memset(a, x, sizeof(a))
#define bit(n, x) (n >> x & 1)
#define pb push_back
#define is insert
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

bool dau(char c){
	return c == '+' or c == '-' or c == '*' or c == '/';
}

void solve(string a){
	queue<int> q;
	for(int i=len(a)-1; i>=0; i--){
		if(a[i] == ' ') continue;
		if(isdigit(a[i])){
			if(isdigit(a[i+1])) continue;
			int so = 0, m = 1;
			for(int j=i; j>=0; j--){
				if(isdigit(a[j])) so += (a[j] - '0') * m, m *= 10;
				else break;
			}q.push(so);
		}else{
			int x = q.front(); q.pop();
			int y = q.front(); q.pop();
			if(a[i] == '+') q.push(x + y);
			else if(a[i] == '-') q.push(y - x);
			else if(a[i] == '*') q.push(x * y);
			else q.push(y / x);
		}
	}
	cout << q.front() << el;
}

void LonggVuz(){
	int n; cin >> n;
	string a; gel(a);
	solve(a);
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}