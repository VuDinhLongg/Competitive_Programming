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

void nhap(int a[], int n){
	for(int i=1; i<=n; i++) cin >> a[i];
}

signed main(){
	LonggVuz();
	
	tc(){
		int n, m, k; cin >> n >> m >> k;
		int a[n+5], b[m+5], c[k+5];
		nhap(a, n); nhap(b, m); nhap(c, k);
		int i = 1, j = 1, h = 1, ok = 0;
		while(i <= n && j <= m && h <= k){
			if(a[i] == b[j] && b[j] == c[h]){
				cout << a[i] << ' '; ok = 1;
				++i; ++j; ++h;
			}else{
				int x = min({a[i], b[j], c[h]});
				if(a[i] == x) ++i;
				if(b[j] == x) ++j;
				if(c[h] == x) ++h;
			}
		}if(!ok) cout << "NO";
		cout << el;
	}
	
	End();
}