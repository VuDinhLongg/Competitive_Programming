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

int bs(int a[], int n, int x){
	int l = 1, r = n;
	while(l <= r){
		int m = (l + r) / 2;
		if(a[m] == x) return m;
		else if(a[m] > x) r = m - 1;
		else l = m + 1;
	}return 0;
}

signed main(){
	LonggVuz();
	
	tc(){
		int n, k; cin >> n >> k;
		int a[n+5];
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}int pos = bs(a, n, k);
		if(pos){
			cout << pos << el;
		}else cout << "NO\n";
	}
	
	End();
}