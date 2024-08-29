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

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

void solve(int a[], int n){
	int td[n+5], gd[n+5];
	for(int i=1; i<=n; i++){
		td[i] = a[i];
		for(int j=1; j<i; j++){
			if(a[i] > a[j]){
				td[i] = max(td[i], td[j] + a[i]);
			}
		}
	}
	for(int i=n; i>=1; i--){
		gd[i] = a[i];
		for(int j=n; j>i; j--){
			if(a[i] > a[j]){
				gd[i] = max(gd[i], gd[j] + a[i]);
			}
		}
	}int res = 0;
	for(int i=1; i<=n; i++){
		res = max(res, td[i] + gd[i] - a[i]);
	}cout << res << el;
}

signed main(){
	LonggVuz();
	
	tc(){
		int n; cin >> n;
		int a[n+5];
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}solve(a, n);
	}
	
	End();
}