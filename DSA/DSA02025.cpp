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
#define pii pair<int, int>

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int n, l, res = oo;
int val[15][15], f[15];
str a[15];

int cnt(str a, str b){
	int cnt = 0, x = 0, y = 0;
	while(x < len(a) && y < len(b)){
		if(a[x] == b[y]){
			++cnt;
			++x; ++y;
		}else{
			if(a[x] < b[y]) ++x;
			else ++y;
		}
	}return cnt;
}

void solve(){
	for(int i=1; i<=n; i++) f[i] = i;
	do{
		int ans = 0;
		for(int i=1; i<n; i++){
			ans += val[f[i]][f[i+1]];
		}res = min(res, ans);
	}while(next_permutation(f+1, f+n+1));
}

signed main(){
	LonggVuz();
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=1; i<n; i++){
		for(int j=i+1; j<=n; j++){
			int tmp = cnt(a[i], a[j]);
			val[i][j] = tmp;
			val[j][i] = tmp;
		}
	}solve();
	cout << res;
	
	End();
}