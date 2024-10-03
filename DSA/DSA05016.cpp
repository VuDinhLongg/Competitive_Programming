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

vector<int> v;
set<int> s;

void hehe(){
	queue<int> q;
	q.push(1);
	while(len(s) < 1e4){
		int x = q.front(); q.pop();
		if(x > 1e18) break;
		v.pb(x);
		if(!s.count(x * 2)){
			q.push(x * 2); s.is(x * 2);
		}
		if(!s.count(x * 3)){
			q.push(x * 3); s.is(x * 3);
		}
		if(!s.count(x * 5)){
			q.push(x * 5); s.is(x * 5);
		}
	}sort(all(v));
}

void LonggVuz(){
	int n; cin >> n;
	cout << v[n - 1] << el;
}

signed main(){
	Sonic();
	
	hehe();
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}