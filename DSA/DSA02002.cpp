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

vector<str> v;
void push(int a[], int n){
	str s = "[";
	for(int i=1; i<n; i++){
		s += to_string(a[i]);
		s += " ";
	}s += to_string(a[n]) + "]";
	v.pb(s);
}

void edit(int a[], int &n){
	for(int i=1; i<n; i++) a[i] += a[i+1];
	--n;
}

void solve(int a[], int n){
	v.clear();
	while(n >= 1){
		push(a, n);
		edit(a, n);
	}reverse(all(v));
	for(auto i : v) cout << i << ' '; cout << el;
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