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

int n, k, a[1005], f[22];
set<int> s;
vector<int> v;

void ql(int i, int x){
	for(int j=x; j<=n; j++){
		f[i] = v[j];
		if(i == k){
			for(int p=1; p<=k; p++) cout << f[p] << ' '; cout << el;
		}else ql(i + 1, j + 1);
	}
}

signed main(){
	LonggVuz();
	
	cin >> n >> k; v.pb(0);
	for(int i=1; i<=n; i++){
		cin >> a[i];
		s.insert(a[i]);
	}n = len(s); k = min(k, n);
	for(int i : s) v.pb(i);
	ql(1, 1);
	
	End();
}