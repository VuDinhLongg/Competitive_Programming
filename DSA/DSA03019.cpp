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

void solve(int x, int y){
	while(1){
		if(y % x){
			int tmp = y / x;
			if(y % x) ++tmp;
			cout << "1/" << tmp << " + ";
			x = x * tmp - y;
			y = y * tmp;
		}else{
			cout << "1/" << y / x << el; return;
		}
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		int x, y; cin >> x >> y;
		solve(x, y);
	}
	
	End();
}