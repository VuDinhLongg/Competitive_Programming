// https://luyencode.net/problem/pairs
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
#define int int32_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e5 + 7;

int f[mxn], v[mxn], id;

int find(int x){
	int res = id, l = 0, r = id - 1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(v[mid] > x){
			res = mid;
			r = mid - 1;
		}else l = mid + 1;
	}return res;
}

void LonggVuz(){
	int n; cin >> n;
	int a[n+5];
	for(int i=1; i<=n; i++){
		cin >> a[i];
		if(a[i] % 2 == 0) v[id++] = i;
	}int pos = n;
	while(pos >= 1 && a[pos] % 2 == 0) --pos;
	for(int i=pos-1; i>=1; i--){
		if(a[i] % 2) pos = i;
		else f[i] = pos;
	}int res = 0;
	for(int it=0; it<id; it++){
		int i = v[it];
		if(f[i] == 0) break;
		for(int j=id-1; v[j] > f[i]; j--){
			if(a[v[j]] < a[i]) ++res;
		}
	}cout << res;
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
