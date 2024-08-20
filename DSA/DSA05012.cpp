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

int c[1005][1005];
void hehe(){
	for(int i=0; i<=1e3; i++){
		for(int j=0; j<=i; j++){
			if(j == 0 || j == i){
				c[i][j] = 1;
			}else{
				c[i][j] = c[i-1][j-1] + c[i-1][j];
				c[i][j] %= mod;
			}
		}
	}
}

signed main(){
	LonggVuz();
	
	hehe();
	tc(){
		int n, k; cin >> n >> k;
		cout << c[n][k] << el;
	}
	
	End();
}