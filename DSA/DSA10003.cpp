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
const int maxn = 1e3 + 7;

int n, m, r[maxn];

int get(int u){
	if(u == r[u]) return u;
	return r[u] = get(r[u]);
}

signed main(){
	LonggVuz();
	
	tc(){
		cin >> n >> m;
		for(int i=1; i<=n; i++) r[i] = i;
		bool ok = 0;
		while(m--){
			int x, y; cin >> x >> y;
			x = get(x); y = get(y);
			if(x == y) ok = 1;
			r[x] = y;
		}if(ok){
			cout << "YES\n";
		}else cout << "NO\n";
	}
	
	End();
}