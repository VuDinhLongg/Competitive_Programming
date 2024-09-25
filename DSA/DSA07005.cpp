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

string edit(string a, int n){
	int ok = 0, sw = 0;
	string res = "";
	for(int i=0; i<n; i++){
		if(isalpha(a[i])){
			res += a[i];
		}else{
			if(a[i] == '('){
				if(a[i-1] == '-'){
					++sw;
					if(ok) ok = 0;
					else ok = 1;
				}
			}else if(a[i] == '+'){
				if(ok) res += '-';
				else res += '+';
			}else if(a[i] == '-'){
				if(ok) res += '+';
				else res += '-';
			}else{
				if(sw > 0){
					--sw;
					if(ok) ok = 0;
					else ok = 1;
				}
			}
		}
	}return res;
}

void LonggVuz(){
	string a; cin >> a;
	cout << edit(a, len(a)) << el;
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}