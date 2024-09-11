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
#define ppi pair<pii, int>

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int n, u, v, s, t;
char a[105][105];

int cal(){
	queue<ppi> q;
	q.push({{u, v}, 0});
	a[u][v] = 'X';
	while(!q.empty()){
		ppi x = q.front(); q.pop();
		pii p = x.fi;
		int b = x.se;
		if(p.fi == s && p.se == t) return b;
		int curx = p.fi, cury = p.se;
		int newx1 = curx - 1, newx2 = curx + 1;
		int newy1 = cury - 1, newy2 = cury + 1;
		while(0 <= newx1 && a[newx1][cury] == '.'){
			q.push({{newx1, cury}, b + 1});
			a[newx1][cury] = 'X';
			--newx1;
		}
		while(newx2 < n && a[newx2][cury] == '.'){
			q.push({{newx2, cury}, b + 1});
			a[newx2][cury] = 'X';
			++newx2;
		}
		while(0 <= newy1 && a[curx][newy1] == '.'){
			q.push({{curx, newy1}, b + 1});
			a[curx][newy1] = 'X';
			--newy1;
		}
		while(newy2 < n && a[curx][newy2] == '.'){
			q.push({{curx, newy2}, b + 1});
			a[curx][newy2] = 'X';
			++newy2;
		}
	}return 0;
}

signed main(){
	LonggVuz();
	
	tc(){
		cin >> n;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> a[i][j];
			}
		}cin >> u >> v >> s >> t;
		cout << cal() << el;
	}
	
	End();
}