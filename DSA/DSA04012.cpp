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
const int maxn = 1e4 + 7;

int f[maxn];

signed main(){
	LonggVuz();
	
	tc(){
		ms(f, 0);
		int n, m; cin >> n >> m;
		int a[n+5], b[m+5];
		for(int i=0; i<n; i++){
			cin >> a[i];
		}
		for(int i=0; i<m; i++){
			cin >> b[i];
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				f[i+j] += a[i] * b[j];
			}
		}int x = n + m - 1;
		for(int i=0; i<x; i++){
			cout << f[i] << ' ';
		}cout << el;
	}
	
	End();
}