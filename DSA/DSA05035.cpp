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

int t[105][15], f[105];
// t[i][j] : số lượng số có i chữ số mà chữ số cuối cùng là j
// f[i] : số lượng số có số chữ số <= i mà các chữ số tăng dần

void hehe(){
	for(int i=1; i<=9; i++) t[1][i] = 1;
	f[1] = 10;
	for(int i=2; i<=100; i++){
		int x = f[i-1]; if(i == 2) --x;
		for(int j=9; j>=1; j--){
			t[i][j] += x; t[i][j] %= mod;
			x -= t[i-1][j]; x = (x + mod) % mod;
			f[i] += t[i][j]; f[i] %= mod;
		}
	}
	for(int i=2; i<=100; i++) f[i] += f[i-1], f[i] %= mod;
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