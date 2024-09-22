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
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int k, n, m, vis[5][5];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
string a[105];
char c[5][5];
vector<string> ve;

void run(int i, int j, string s){
	vis[i][j] = 1;
	s.push_back(c[i][j]);
	if(binary_search(a, a + k, s)) ve.push_back(s);
	for(int x=0; x<8; x++){
		int i1 = i + dx[x];
		int j1 = j + dy[x];
		if(i1 >= 1 and i1 <= n and j1 >= 1 and j1 <= m){
			if(!vis[i1][j1]) run(i1, j1, s);
		}
	}vis[i][j] = 0;
}

void LonggVuz(){
	ve.clear();
	cin >> k >> n >> m;
	for(int i=0; i<k; i++){
		cin >> a[i];
	}sort(a, a + k);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++) cin >> c[i][j];
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			ms(vis, 0);
			run(i, j, "");
		}
	}
	if(!ve.empty()){
		for(string s : ve){
			cout << s << ' ';
		}cout << el;
	}else cout << "-1\n";
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}