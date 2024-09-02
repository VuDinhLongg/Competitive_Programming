// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Noob C++
void End(){
    cerr << "=> Thời gian code chạy: ";
    cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define LonggVuz() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define ms(a, x) memset(a, x, sizeof(a))
#define tc() int TC; cin >> TC; while(TC--)
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define str string
#define int intmax_t
#define ld long double
#define pci pair<char, int>

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;



signed main(){
	LonggVuz();
	
	int n; str a; cin >> n >> a;
	int res = 0, x = 0, t = 0;
	for(char &c : a){
		if(c == 'X') ++x, ++t;
		else if(c == 'T') ++t;
	}
	for(int i=0; i<x; i++){
		if(a[i] == 'D'){
			for(int j=n-1; j>=x; j--){
				if(a[j] == 'X'){
					++res;
					swap(a[i], a[j]); break;
				}
			}
		}else if(a[i] == 'T'){
			for(int j=x; j<n; j++){
				if(a[j] == 'X'){
					++res;
					swap(a[i], a[j]); break;
				}
			}
		}
	}
	for(int i=x; i<t; i++){
		if(a[i] != 'T'){
			for(int j=n-1; j>=t; j--){
				if(a[j] == 'T'){
					++res;
					swap(a[i], a[j]); break;
				}
			}
		}
	}cout << res; //cout << el << a;
	
	End();
}