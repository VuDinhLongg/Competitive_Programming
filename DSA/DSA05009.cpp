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

bool f[40004];
str check(int a[], int n, int s){
	ms(f, 0);
	f[0] = 1;
	for(int i=1; i<=n; i++){
		for(int j=s; j>=a[i]; j--){
			if(f[j - a[i]]) f[j] = 1;
		}
	}if(f[s]) return "YES\n";
	return "NO\n";
}

signed main(){
	LonggVuz();
	
	tc(){
		int n; cin >> n;
		int a[n+5], sum = 0;
		for(int i=1; i<=n; i++){
			cin >> a[i];
			sum += a[i];
		}if(sum % 2){
			cout << "NO\n";
		}else cout << check(a, n, sum / 2);
	}
	
	End();
}