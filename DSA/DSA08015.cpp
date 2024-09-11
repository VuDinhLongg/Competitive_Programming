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

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int n, m, p, s1, s2, s3, e1, e2, e3;
int dx[] = {-1, 0, 0, 0, 0, 1};
int dy[] = {0, -1, 0, 1, 0, 0};
int dz[] = {0, 0, -1, 0, 1, 0};
char a[33][33][33];

struct td{
	int x, y, z, step;
};

void input(){
	cin >> n >> m >> p;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			for(int k=1; k<=p; k++){
				cin >> a[i][j][k];
				if(a[i][j][k] == 'S'){
					s1 = i; s2 = j; s3 = k;
				}else if(a[i][j][k] == 'E'){
					e1 = i; e2 = j; e3 = k;
				}
			}
		}
	}
}

bool ok(int i, int mx){
	return 1 <= i && i <= mx;
}

int cal(){
	queue<td> q;
	q.push({s1, s2, s3, 0});
	a[s1][s2][s3] = '#';
	a[e1][e2][e3] = '.';
	while(!q.empty()){
		td d = q.front(); q.pop();
		if(d.x == e1 && d.y == e2 && d.z == e3) return d.step;
		for(int i=0; i<6; i++){
			int new_x = d.x + dx[i];
			int new_y = d.y + dy[i];
			int new_z = d.z + dz[i];
			if(ok(new_x, n) && ok(new_y, m) && ok(new_z, p)){
				if(a[new_x][new_y][new_z] == '.'){
					q.push({new_x, new_y, new_z, d.step + 1});
					a[new_x][new_y][new_z] = '#';
				}
			}
		}
	}return -1;
}

signed main(){
	LonggVuz();
	
	tc(){
		input();
		cout << cal() << el;
	}
	
	End();
}