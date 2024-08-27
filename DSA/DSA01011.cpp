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

void solve(str a, int n){
	int x[n+5], y[n+5];
	for(int i=0; i<n; i++) x[i] = a[i] - '0', y[i] = x[i];
	next_permutation(x, x + n);
	reverse(y, y + n);
	bool ok = 0;
	for(int i=0; i<n; i++){
		if(x[i] != y[i]){
			ok = 1; break;
		}
	}if(!ok){
		cout << "BIGGEST\n"; return;
	}
	for(int i=0; i<n; i++){
		cout << x[i];
	}cout << el;
}

signed main(){
	LonggVuz();
	
	tc(){
		int id; str a; cin >> id >> a;
		cout << id << ' ';
		solve(a, len(a));
	}
	
	End();
}