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

int n, c[20][20], res = oo;
bool vis[20];

void run(int id, int d, int sum){
	if(id == n){
		res = min(res, sum + c[d][1]); 
		return;
	}
	for(int i=2; i<=n; i++){
		if(!vis[i] && sum + c[d][i] < res){
			vis[i] = 1;
			run(id + 1, i, sum + c[d][i]);
			vis[i] = 0;
		}
	}
}

signed main(){
	LonggVuz();
	
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> c[i][j];
		}
	}run(1, 1, 0);
	cout << res;
	
	End();
}