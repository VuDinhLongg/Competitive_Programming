/*
  https://luyencode.net/problem/balls
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
using ll = unsigned long long;
using ld = long double;
using str = string;

ll mod = 1e9 + 7;

int main(){
	LonggVu();
	
	ll n; cin >> n;
	n += 1; n %= mod;
	ll res = n * n - 1;
	cout << res % mod;
	
	End();
}
