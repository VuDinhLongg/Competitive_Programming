// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Legendary Grandmaster
void End(){
    cerr << "=> Thời gian code chạy: ";
    cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define Sonic() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define ms(a, x) memset(a, x, sizeof(a))
#define bit(n, x) (n >> x & 1)
#define pb push_back
#define is insert
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e5 + 7;

int n, m, r[maxn], sz[maxn], c[maxn];

int get(int u){
	if(u == r[u]) return u;
	return r[u] = get(r[u]);
}

void LonggVuz(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		r[i] = i;
		sz[i] = 1;
		c[i] = 0;
	}
	while(m--){
		int x, y; cin >> x >> y;
		x = get(x); y = get(y);
		if(x == y){
			++c[x]; continue;
		}
		if(x > y) swap(x, y);
		r[y] = x;
		sz[x] += sz[y];
		c[x] += c[y] + 1;
	}
	for(int i=1; i<=n; i++){
		int u = get(i);
		if(u > 0){
			if(c[u] * 2 != sz[u] * (sz[u] - 1)){
				cout << "NO\n"; return;
			}r[u] = 0;
		}
	}cout << "YES\n";
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}