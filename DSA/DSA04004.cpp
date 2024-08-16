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

int v[55];

signed main(){
	LonggVuz();
	
	v[1] = 2;
	for(int i=2; i<=50; i++) v[i] = v[i-1] * 2;
	tc(){
		int n, k; cin >> n >> k;
		int x = v[n] - 1;
		while(k != x - k + 1){
			k = min(k, x - k + 1);
			--n;
			x = v[n] - 1;
		}cout << n << el;
	}
	
	End();
}