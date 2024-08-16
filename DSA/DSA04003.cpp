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

const int mod = 123456789;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int mu(int a, int b){
	a %= mod;
	int res = 1;
	while(b){
		if(b%2){
			res = (res * a) % mod;
		}b /= 2;
		a = (a * a) % mod;
	}return res;
}

signed main(){
	LonggVuz();
	
	tc(){
		int n; cin >> n;
		cout << mu(2, n - 1) << el;
	}
	
	End();
}