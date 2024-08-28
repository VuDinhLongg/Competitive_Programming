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

void solve(int n){
	int l = n / 7, x = n - 7 * l;
	str res = str(l, '7');
	while(x % 4){
		if(res.empty()) break;
		res.pop_back();
		x += 7;
	}if(x % 4 == 0){
		res += str(x / 4, '4');
		sort(all(res));
		cout << res << el;
	}else cout << "-1\n";
}

signed main(){
	LonggVuz();
	
	tc(){
		int n; cin >> n;
		solve(n);
	}
	
	End();
}