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

pii p[10][10];
bool vis[10][10];
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int num(char c){
	return c - 'a' + 1;
}

void bfs(pii s, pii t){
	queue<pii> q;
	q.push(s);
	while(!q.empty()){
		pii x = q.front(); q.pop();
		if(x.fi == t.fi && x.se == t.se) break;
		for(int i=0; i<8; i++){
			int new_x = x.fi + dx[i];
			int new_y = x.se + dy[i];
			if(new_x >= 1 && new_x <= 8 && new_y >= 1 && new_y <= 8 && !vis[new_x][new_y]){
				vis[new_x][new_y] = 1;
				q.push({new_x, new_y});
				p[new_x][new_y] = {x.fi, x.se};
			}
		}
	}int res = 0;
	while(!(t.fi == s.fi && t.se == s.se)){
		++res;
		pii tmp = t;
		t.fi = p[tmp.fi][tmp.se].fi;
		t.se = p[tmp.fi][tmp.se].se;
	}cout << res << el;
}

void solve(str a, str b){
	ms(p, {}); ms(vis, 0);
	pii s = {num(a[0]), a[1] - '0'};
	pii t = {num(b[0]), b[1] - '0'};
	//cout << s.fi << s.se << ' ' << t.fi << t.se << el;
	bfs(s, t);
}

signed main(){
	LonggVuz();
	
	tc(){
		str a, b; cin >> a >> b;
		solve(a, b);
	}
	
	End();
}