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

int n, m, color[1005];
vector<int> a[1005];

bool check(int u){
	queue<int> q;
	q.push(u);
	color[u] = 1;
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int &x : a[v]){
			if(color[x] == 0){
				if(color[v] == 1) color[x] = 2;
				else color[x] = 1;
				q.push(x);
			}else if(color[x] == color[v]) return 0;
		}
	}return 1;
}

signed main(){
	LonggVuz();
	
	tc(){
		cin >> n >> m;
		while(m--){
			int x, y; cin >> x >> y;
			a[x].pb(y); a[y].pb(x);
		}bool ok = 1;
		for(int i=1; i<=n; i++){
			if(color[i] == 0){
				if(!check(i)){
					ok = 0; break;
				}
			}
		}if(ok){
			cout << "YES\n";
		}else cout << "NO\n";
		for(int i=1; i<=n; i++){
			a[i].clear();
			color[i] = 0;
		}
	}
	
	End();
}