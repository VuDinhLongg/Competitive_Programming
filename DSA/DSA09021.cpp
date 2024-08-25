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

vector<int> v[1005];

signed main(){
	LonggVuz();
	
	int n; cin >> n;
	bool a[n+5][n+5];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> a[i][j];
			if(a[i][j]){
				v[i].pb(j);
			}
		}
	}
	for(int i=1; i<=n; i++){
		sort(all(v[i]));
		for(int j : v[i]){
			cout << j << ' ';
		}cout << el;
	}
	
	End();
}