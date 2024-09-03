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

int n, m, k, color[105];
vector<int> a[105];

bool check(int i){
	for(int j=1; j<=k; j++){
		bool ok = 1;
		for(int &x : a[i]){
			if(j == color[x]){
				ok = 0; break;
			}
		}if(ok){
			color[i] = j;
			if(i == n || check(i + 1)) return 1;
		}
	}return 0;
}

signed main(){
	LonggVuz();
	
	tc(){
		cin >> n >> m >> k;
		while(m--){
			int x, y; cin >> x >> y;
			a[x].pb(y); a[y].pb(x);
		}if(check(1)){
			cout << "YES\n";
		}else cout << "NO\n";
		for(int i=1; i<=n; i++) a[i].clear(), color[i] = 0;
	}
	
	End();
}