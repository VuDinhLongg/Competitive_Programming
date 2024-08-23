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
#define db double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

stack<str> st;
void in(int a[], int n, int &x){
	str s = "Buoc "; s += to_string(x++) + ": ";
	for(int i=1; i<=n; i++) s += to_string(a[i]) + " "; s += "\n";
	st.push(s);
}

signed main(){
	LonggVuz();
	
	tc(){
		int n; cin >> n;
		int a[n+5];
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}int b = 1;
		for(int i=1; i<n; i++){
			bool ok = 0;
			for(int j=1; j<n; j++){
				if(a[j] > a[j+1]){
					swap(a[j], a[j+1]);
					ok = 1;
				}
			}if(ok) in(a, n, b);
		}
		while(!st.empty()){
			cout << st.top(); st.pop();
		}
	}
	
	End();
}