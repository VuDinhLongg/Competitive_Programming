// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Legendary Grandmaster
void End(){
    cerr << "=> Thời gian code chạy: ";
    cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define Sonic() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define ms(a, x) memset(a, x, sizeof(a))
#define bit(n, x) (n >> x & 1)
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

bool check(int a[], int n){
	for(int i=n; i>2; i--){
		int l = 1, r = i - 1;
		while(l <= r){
			int x = a[l] + a[r];
			if(x == a[i]) return 1;
			else if(x > a[i]) --r;
			else ++l;
		}
	}return 0;
}

void LonggVuz(){
	int n; cin >> n;
	int a[n+5];
	for(int i=1; i<=n; i++){
		cin >> a[i];
		a[i] *= a[i];
	}sort(a+1, a+n+1);
	if(check(a, n)){
		cout << "YES\n";
	}else cout << "NO\n";
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
