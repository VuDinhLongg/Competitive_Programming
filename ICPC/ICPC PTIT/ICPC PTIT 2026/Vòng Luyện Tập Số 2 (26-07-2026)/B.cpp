/*======================
   Author : @LonggVuz
======================*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define orz(...) 2005
#endif

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 1'000'007

int n, m, ok, vis[25][25];
char a[25][25];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
vector<pair<int, int>> v;

void dfs(int i, int j){
	if(i == 1 or i == n or j == 1 or j == m) ok = 0;
	v.push_back({i, j});
	vis[i][j] = 1;
	fo(k, 0, 3){
		int ii = i + dx[k];
		int jj = j + dy[k];
		if(1 <= ii and ii <= n and 1 <= jj and jj <= m and !vis[ii][jj] and a[ii][jj] == 'O') dfs(ii, jj);
	}
}

inline void LonggVuz(){
	cin >> n >> m;
	fo(i, 1, n) fo(j, 1, m){
		cin >> a[i][j];
		vis[i][j] = 0;
	}
	fo(i, 2, n - 1) fo(j, 2, m - 1) if(!vis[i][j] and a[i][j] == 'O'){
		ok = 1;
		v.clear();
		dfs(i, j);
		if(ok){
			for(auto &[x, y] : v) a[x][y] = 'X';
		}
	}
	fo(i, 1, n){
		fo(j, 1, m) cout << a[i][j] << ' ';
		el;
	}
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(1) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}