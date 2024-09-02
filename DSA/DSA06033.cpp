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
#define pii pair<int, int>

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e5 + 7;

int f[maxn];

void solve(int a[], int n){
	int res = -1;
	f[n] = a[n];
	for(int i=n-1; i>=1; i--) f[i] = max(f[i + 1], a[i]);
	int i = 1, j = 1;
	while(i <= n && j <= n){
		if(a[i] < f[j]){
			res = max(res, j - i);
			++j;
		}else ++i;
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