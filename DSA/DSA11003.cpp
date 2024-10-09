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

int find(int in[], int n, int x){
	for(int i=0; i<n; i++){
		if(in[i] == x) return i;
	}return -1;
}

void postOrder(int in[], int pre[], int n){
	int pos = find(in, n, pre[0]);
	if(pos > 0) postOrder(in, pre + 1, pos);
	if(pos < n - 1) postOrder(in + pos + 1, pre + pos + 1, n - pos - 1);
	cout << pre[0] << ' ';
}

void LonggVuz(){
	int n; cin >> n;
	int in[n], pre[n];
	for(int i=0; i<n; i++) cin >> in[i];
	for(int i=0; i<n; i++) cin >> pre[i];
	postOrder(in, pre, n);
	cout << el;
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}