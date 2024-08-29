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
const int maxn = 1e4 + 7;

int f[maxn];
void hehe(){
	f[1] = 1;
	for(int i=2; i<=1e4; i++){
		f[i] = f[i-1] + 1;
		int c = sqrtl(i);
		for(int j=1; j<=c; j++){
			 f[i] = min(f[i], f[i - j * j] + 1);
		}
	}
}

signed main(){
	LonggVuz();
	
	hehe();
	tc(){
		int n; cin >> n;
		cout << f[n] << el;
	}
	
	End();
}