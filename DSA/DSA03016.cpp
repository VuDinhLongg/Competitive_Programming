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

void solve(int s, int d){
	if(d * 9 < s){
		cout << "-1\n"; return;
	}
	str res = "";
	for(int x=1; x<=d; x++){
		for(int i=9; i>=0; i--){
			if(s >= i){
				s -= i;
				res.pb(i + '0');
				break;
			}
		}
	}sort(all(res));
	if(res[0] == '0'){
		for(int i=1; i<d; i++){
			if(res[i] != '0' && res[i-1] == '0'){
				--res[i];
				break;
			}
		}++res[0];
	}cout << res << el;
}

signed main(){
	LonggVuz();
	
	tc(){
		int s, d; cin >> s >> d;
		solve(s, d);
	}
	
	End();
}