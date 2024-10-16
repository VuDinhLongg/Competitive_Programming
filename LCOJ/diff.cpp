/*
    Problem: luyencode.net/problem/diff
*/
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

int val(int a, int b){
	return (b + a) * (b - a + 1) / 2;
}

void LonggVuz(){
	int a, b; cin >> a >> b;
	int res = oo, mi = oo;
	int l = a, r = b;
	while(l <= r){
		int m = (l + r) / 2;
		int trai = val(a, m);
		int phai = val(m + 1, b);
		if(abs(trai - phai) < mi){
			mi = abs(trai - phai);
			res = m;
		}
		if(trai == phai){
			cout << res; return;
		}else if(trai < phai){
			if(m < 0) r = m - 1;
			else l = m + 1;
		}else{
			if(m > 0) r = m - 1;
			else l = m + 1;
		}
	}cout << res;
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
