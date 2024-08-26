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

int n, k, a[105], res;
vector<int> v[105], x;

void ql(int i){

	if(len(x) == k){
		++res; return;
	}
	for(int j : v[i]){
		if(k - len(x) - 1 <= n - j + 1){
			x.pb(j);
			ql(j);
			x.pop_back();
		}
	}
}

signed main(){
	LonggVuz();
	
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=n-1; i>=0; i--){
		for(int j=i+1; j<=n; j++){
			if(a[j] > a[i]){
				v[i].pb(j);
			}
		}
	}ql(0);
	cout << res;
	
	End();
}