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

int rev(int n){
	int res = 0;
	while(n){
		res = res * 10 + n % 10;
		n /= 10;
	}return res;
}

int mu(int n, int k){
	if(!k) return 1;
	int x = mu(n, k / 2);
	if(k%2 == 0) return x * x % mod;
	return n * (x * x % mod) % mod;
}

signed main(){
	LonggVuz();
	
	tc(){
		int n; cin >> n;
		int k = rev(n);
		cout << mu(n, k) << el;
	}
	
	End();
}