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



signed main(){
	LonggVuz();
	
	int n; cin >> n;
	int a[n+5];
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}int res = oo, mi = *min_element(a+1, a+n+1);
	for(int i=1; i<=mi; i++){
		int ans = 0, ok = 1;
		for(int j=1; j<=n; j++){
			int x = a[j] / (i + 1) + 1;
			if(a[j] / x != i){
				ok = 0; break;
			}ans += x;
		}if(ok) res = min(res, ans);
	}cout << res << el;
	
	End();
}