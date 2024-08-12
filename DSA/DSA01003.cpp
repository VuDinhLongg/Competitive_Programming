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

void in(int a[], int n){
	for(int i=1; i<=n; i++){
		cout << a[i] << ' ';
	}cout << el;
}

void solve(int a[], int n){
	bool mark[n+5] = {0};
	mark[a[n]] = 1;
	for(int i=n-1; i>=1; i--){
		bool ok = 0;
		for(int j=a[i]+1; j<=n; j++){
			if(mark[j]){
				a[i] = j;
				ok = 1; break;
			}
		}if(ok){
			ms(mark, 0);
			for(int j=1; j<=i; j++){
				mark[a[j]] = 1;
			}int so = 1;
			for(int j=i+1; j<=n; j++){
				while(mark[so]) ++so;
				a[j] = so; mark[so] = 1;
			}return;
		}else mark[a[i]] = 1;
	}for(int i=1; i<=n; i++) a[i] = i;
}

signed main(){
	LonggVuz();
	
	tc(){
		int n; cin >> n;
		int a[n+5];
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}solve(a, n); in(a, n);
	}
	
	End();
}