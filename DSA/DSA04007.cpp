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

str tong(str a, str b, int k){
	if(len(a) == len(b) && a < b) swap(a, b);
	if(len(a) < len(b)) swap(a, b);
	int n = len(a), m = len(b);
	while(len(b) < n) b = "0" + b;
	reverse(all(a)); reverse(all(b));
	str res = string(n, 0);
	int nho = 0;
	for(int i=0; i<n; i++){
		int tmp = (a[i] - '0') + (b[i] - '0') + nho;
		int x = tmp % k;
		res[i] += x + '0';
		nho = tmp / k;
	}if(nho){
		res.pb(nho + '0');
	}reverse(all(res));
	return res;
}

signed main(){
	LonggVuz();
	
	tc(){
		int k; str a, b; cin >> k >> a >> b;
		cout << tong(a, b, k) << el;
	}
	
	End();
}