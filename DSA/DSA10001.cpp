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
const int maxn = 1e6 + 7;

struct pe{
	int x, y, z;
	char c;
};

int n, m, u, v, s, t;
char a[505][505];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
string h = "ULDR";

bool check(int i, int j){
	return (1 <= i and i <= n) and (1 <= j and j <= m) and (a[i][j] == '.');
}

bool bfs(){
	queue<pe> q;
	for(int i=0; i<4; i++){
		if(check(u + dx[i], v + dy[i])){
			q.push({u + dx[i], v + dy[i], 0, h[i]});
		}
	}
	while(!q.empty()){
		pe p = q.front(); q.pop();
		if(p.x == s and p.y == t) return 1;
		for(int i=0; i<4; i++){
			if(check(p.x + dx[i], p.y + dy[i])){
				if(p.z < 2 and p.c != h[i]){
					q.push({p.x + dx[i], p.y + dy[i], p.z + 1, h[i]});
					a[p.x + dx[i]][p.y + dy[i]] = '*';
				}else if(p.c == h[i]){
					q.push({p.x + dx[i], p.y + dy[i], p.z, p.c});
					a[p.x + dx[i]][p.y + dy[i]] = '*';
				}
			}
		}
	}return 0;
}

void LonggVuz(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> a[i][j];
			if(a[i][j] == 'S'){
				u = i; v = j;
				a[i][j] = '*';
			}else if(a[i][j] == 'T'){
				s = i; t = j;
				a[i][j] = '.';
			}
		}
	}if(bfs()){
		cout << "YES\n";
	}else cout << "NO\n";
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}