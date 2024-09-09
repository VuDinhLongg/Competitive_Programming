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
#define int int32_t
#define ld long double
#define pii pair<int, int>

const int mod = 1e9 + 7;
//const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int n, k, m, x[105][105];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool vis[105][105];
pii a[105];
map<pair<pii, pii>, int> mark;

void nhap(){
	cin >> n >> k >> m;
	while(m--){
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		mark[{{x1, y1}, {x2, y2}}] = 1;
		mark[{{x2, y2}, {x1, y1}}] = 1;
	}
	for(int i=1; i<=k; i++){
		cin >> a[i].fi >> a[i].se;
	}
}

void edit(int i, int j, int color){
	queue<pii> q;
	q.push({i, j});
	vis[i][j] = 1;
	while(!q.empty()){
		pii t = q.front(); q.pop();
		x[t.fi][t.se] = color;
		for(int k=0; k<4; k++){
			int i1 = t.fi + dx[k];
			int j1 = t.se + dy[k];
			if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n){
				if(mark[{{t.fi, t.se}, {i1, j1}}] == 0 && vis[i1][j1] == 0){
					q.push({i1, j1});
					vis[i1][j1] = 1;
				}
			}
		}
	}
}

void toMau(){
	int color = 1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(x[i][j] == 0 && !vis[i][j]){
				edit(i, j, color);
				++color;
			}
		}
	}
}

signed main(){
	LonggVuz();
	
	nhap();
	toMau();
	int res = 0;
	for(int i=1; i<k; i++){
		for(int j=i+1; j<=k; j++){
			if(x[a[i].fi][a[i].se] != x[a[j].fi][a[j].se]){
				++res;
			}
		}
	}cout << res;
	
	End();
}