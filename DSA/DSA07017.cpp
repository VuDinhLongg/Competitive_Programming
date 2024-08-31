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

void solve(int a[], int n){
	a[n+1] = -1;
	stack<int> st1, st2;
	st1.push(n); st2.push(n);
	int f1[n+5], f2[n+5];
	f1[n] = n; f2[n] = n + 1;
	for(int i=n-1; i>=1; i--){
		while(!st1.empty() && a[i] >= a[st1.top()]){
			st1.pop();
		}if(st1.empty()){
			f1[i] = n;
		}else f1[i] = st1.top();
		st1.push(i);
		while(!st2.empty() && a[i] <= a[st2.top()]){
			st2.pop();
		}if(st2.empty()){
			f2[i] = n + 1;
		}else f2[i] = st2.top();
		st2.push(i);
	}
	for(int i=1; i<=n; i++){
		cout << a[f2[f1[i]]] << ' ';
	}cout << el;
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