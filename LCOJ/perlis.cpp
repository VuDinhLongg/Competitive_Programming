/*
  https://luyencode.net/problem/perlis
*/
// LonggVu.
#include<bits/stdc++.h>
using namespace std;
// Noob C++
void End(){
	cerr << "=> Thời gian code chạy: ";
	cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define LonggVu() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
using ll = long long;
using ld = long double;
using str = string;

int maxx = -1e6;
void solve(int a[], int n){
	int x = n, r[n+5];
	for(int i=1; i<=maxx; i++){
		for(int j=1; j<=n; j++){
			if(a[j] == i){
				r[j] = x;
				--x;
			}
		}
	}
	for(int i=1; i<=n; i++){
		cout << r[i] << ' ';
	}
}

int main(){
	LonggVu();
	
	int n; cin >> n;
	int a[n+5];
	for(int i=1; i<=n; i++){
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}solve(a, n);
	
	End();
}
