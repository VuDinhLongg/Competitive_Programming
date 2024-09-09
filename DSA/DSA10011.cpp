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
#define int int64_t
#define ld long double
#define pii pair<int, int>
#define pip pair<int, pii>

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int n, m, a[505][505], f[505][505];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void input(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> a[i][j];
			f[i][j] = oo;
		}
	}
}

bool check(int i, int j){
	return (i >= 1 && i <= n) && (j >= 1 && j <= m);
}

void solve(){
	f[1][1] = a[1][1];
	priority_queue<pip, vector<pip>, greater<pip>> q;
	q.push({a[1][1], {1, 1}});
	while(!q.empty()){
		pip top = q.top(); q.pop();
		pii td = top.se;
		int kc = top.fi;
		if(kc > f[td.fi][td.se]) continue;
		for(int k=0; k<4; k++){
			int new_x = td.fi + dx[k];
			int new_y = td.se + dy[k];
			if(!check(new_x, new_y)) continue;
			if(f[td.fi][td.se] + a[new_x][new_y] < f[new_x][new_y]){
				f[new_x][new_y] = f[td.fi][td.se] + a[new_x][new_y];
				q.push({f[new_x][new_y], {new_x, new_y}});
			}
		}
	}cout << f[n][m] << el;
}

signed main(){
	LonggVuz();
	
	tc(){
		input();
		solve();
	}
	
	End();
}