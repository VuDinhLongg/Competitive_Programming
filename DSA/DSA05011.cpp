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
#define ms(x) memset(x, 0, sizeof(x))
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

int f[105][50005];
// f[i][j] : so luong so co i chu so, tong cac chu so bang j
void hehe(){
	for(int i=0; i<=9; i++) f[1][i] = 1;
	for(int i=2; i<=100; i++){
		for(int j=1; j<=900; j++){
			f[i][j] = f[i-1][j];
			for(int k=1; k<=9; k++){
				if(j <= k) continue;
				f[i][j] += f[i-1][j-k];
				f[i][j] %= mod;
			}
		}
	}
}

signed main(){
	LonggVuz();
	
	hehe();
	tc(){
		int n, k; cin >> n >> k;
		cout << f[n][k] << el;
	}
	
	End();
}