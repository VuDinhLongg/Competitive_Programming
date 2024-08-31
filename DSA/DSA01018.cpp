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

void solve(int a[], int n, int k){
	bool cuoi = 1;
	for(int i=1; i<=k; i++){
		if(a[i] != i){
			cuoi = 0; break;
		}
	}if(cuoi){
		for(int i=n-k+1; i<=n; i++) cout << i << ' '; cout << el;
	}else{
		for(int i=k; i>=1; i--){
			if(a[i] - 1 != a[i-1]){
				--a[i];
				int x = n;
				for(int j=k; j>i; j--){
					a[j] = x; --x;
				}break;
			}
		}
		for(int i=1; i<=k; i++) cout << a[i] << ' '; cout << el;
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		int n, k; cin >> n >> k;
		int a[k+5]; a[0] = -1;
		for(int i=1; i<=k; i++){
			cin >> a[i];
		}solve(a, n, k);
	}
	
	End();
}