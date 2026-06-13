/*
    vudinhlong 12:57:01 sa, 16/12/2024
    => Old style, update later... :D
*/

// LonggVuz
#include<bits/stdc++.h>
using namespace std;
// ☞ Think twice, code once ☜
void End(){
    cerr << "=> Smoothly Finished! Time taken: ";
    cerr << (0.001 * clock()) << "s" << string(25, '\t');
}
#define Sonic() cin.tie(0) -> sync_with_stdio(0)
#define out(x) return cout << x, void()
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define pb push_back
#define is insert
#define el '\n'
#define ld long double

const int mod = 1e9 + 7;
const int mxn = 1e6 + 7;

int n; string a;
set<string> s;

bool check(int l, int r, int ok){
	string str = "";
	int mxl = r;
	while(l < mxl and r < n){
		if(a[l] != a[r]){
			if(ok > 0){
				--ok;
				++l;
				continue;
			}else if(ok < 0){
				++ok;
				++r;
				continue;
			}else return 0;
		}
		str.pb(a[l]);
		++l; ++r;
	}s.is(str);
	return 1;
}

void LonggVuz(){
	cin >> n >> a;
	if(n % 2 == 0) out("No Solution");
	bool ok1 = check(0, n / 2, -1);
	bool ok2 = check(0, n / 2 + 1, 1);
	if(ok1 or ok2){
		if(len(s) == 1) cout << *s.begin();
		else cout << "Multiple Solutions";
	}else cout << "No Solution";
}

signed main(){
	Sonic();
	
	signed test = 1;
	//cin >> test;
	for(signed i=1; i<=test; i++){
		LonggVuz();
	}
	
	End();
}
