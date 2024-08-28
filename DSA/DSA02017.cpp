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

int res, a[10][10], x[20], y[20], vis[10];
void ql(int h, int sum){
	if(h == 9){
		res = max(res, sum); return;
	}
	for(int i=1; i<=8; i++){
		if(!vis[i] && !x[h+i-1] && !y[h-i+8]){
			vis[i] = x[h+i-1] = y[h-i+8] = 1;
			ql(h + 1, sum + a[h][i]);
			vis[i] = x[h+i-1] = y[h-i+8] = 0;
		}
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		ms(x, 0); ms(y, 0); ms(vis, 0);
		res = 0;
		for(int i=1; i<=8; i++){
			for(int j=1; j<=8; j++){
				cin >> a[i][j];
			}
		}ql(1, 0);
		cout << res << el;
	}
	
	End();
}