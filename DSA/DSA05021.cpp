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
#define ms(x) memset(x, 0, sizeof(x))
#define tc() int TC; cin >> TC; while(TC--)
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define str string
#define int intmax_t
#define ld long double
#define pii pair<int, int>

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int f[105];
bool cmp(pii a, pii b){
	return a.se < b.se;
}

void solve(pii a[], int n){
	sort(a+1, a+n+1, cmp);
	int res = 0;
	for(int i=1; i<=n; i++){
		f[i] = 1;
		for(int j=1; j<i; j++){
			if(a[i].fi > a[j].se){
				f[i] = max(f[i], f[j] + 1);
			}
		}res = max(res, f[i]);
	}cout << res << el;
}

signed main(){
	LonggVuz();
	
	tc(){
		int n; cin >> n;
		pii a[n+5];
		for(int i=1; i<=n; i++){
			cin >> a[i].fi >> a[i].se;
		}solve(a, n);
	}
	
	End();
}