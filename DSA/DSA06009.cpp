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
#define db long double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;



signed main(){
	LonggVuz();
	
	tc(){
		int n, m; cin >> n >> m;
		db a[n+5], b[m+5];
		for(int i=1; i<=n; i++){
			cin >> a[i];
			a[i] = log(a[i]) / a[i];
		}sort(a+1, a+n+1);
		for(int i=1; i<=m; i++){
			cin >> b[i];
			b[i] = log(b[i]) / b[i];
		}//sort(b+1, b+m+1, greater<db>());
		int res = 0;
		for(int i=1; i<=m; i++){
			int pos = upper_bound(a+1, a+n+1, b[i]) - a;
			res += n - pos + 1;
		}cout << res << el;
	}
	
	End();
}