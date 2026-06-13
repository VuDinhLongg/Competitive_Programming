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
const int mxn = 1e5 + 7;

int f[mxn];

int get(int x){
	int res = 0;
	while(x < mxn){
		res += f[x];
		x += x & -x;
	}return res;
}

void update(int x){
	while(x > 0){
		++f[x];
		x -= x & -x;
	}
}

void LonggVuz(){
	int n; cin >> n;
	int a[n+5];
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	int res = 0;
	stack<int> st;
	for(int i=1; i<=n; i++){
		if(a[i] % 2 == 0){
			res += get(a[i] + 1);
			st.push(a[i]);
		}else{
			while(!st.empty()){
				update(st.top());
				st.pop();
			}
		}
	}cout << res << el;
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
