// https://luyencode.net/problem/deadline
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

int m = 1e9 + 7;

signed main(){
	LonggVuz();
	
	int n; cin >> n;
	int a[n+5], res = 1;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}sort(a, a + n);
	for(int i=0; i<n; i++){
		res *= (a[i] - i);
		res %= m;
	}cout << res;
	
	End();
}
