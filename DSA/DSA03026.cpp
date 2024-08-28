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

void solve(int n, int s){
	str x = "", y = "";
	for(int x=1; x<=n; x++){
		for(int i=9; i>=0; i--){
			if(s >= i){
				s -= i;
				y.pb(i + '0');
				break;
			}
		}
	}x = y; reverse(all(x));
	if(x[0] == '0'){
		for(int i=1; i<n; i++){
			if(x[i] != '0' && x[i-1] == '0'){
				--x[i]; break;
			}
		}++x[0];
	}cout << x << ' ' << y;
}

signed main(){
	LonggVuz();
	
	int n, s; cin >> n >> s;
	if(n * 9 < s || s == 0){
		cout << "-1 -1";
	}else solve(n, s);
	
	End();
}