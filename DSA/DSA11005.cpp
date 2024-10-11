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
const int mxn = 1e4 + 7;

int pos[mxn];
int find(int in[], int n){
	int goc = 0;
	for(int i=goc+1; i<n; i++){
		if(pos[in[i]] < pos[in[goc]]){
			goc = i;
		}
	}
	return goc;
}

void postOrder(int in[], int n){
	int goc = find(in, n);
	if(goc > 0) postOrder(in, goc);
	if(goc < n - 1) postOrder(in + goc + 1, n - goc - 1);
	cout << in[goc] << ' ';
}

void LonggVuz(){
	ms(pos, -1);
	int n; cin >> n;
	int in[n], lev[n];
	for(int i=0; i<n; i++){
		cin >> in[i];
	}
	for(int i=0; i<n; i++){
		cin >> lev[i];
		if(pos[lev[i]] == -1) pos[lev[i]] = i;
	}
	postOrder(in, n);
	cout << el;
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}