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

#define el cout << '\n'
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 1'000'007
#define ai3 array<int, 3>
#define ai4 array<int, 4>
#define pii pair<int, int>
#define fi first
#define se second
#define mask(n) (1ll << (n))
#define bit(n, i) ((n) >> (i) & 1)
#define one(n) __builtin_popcountll(n)
#define clz(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctzll(n)

int n, m, s, idx[101][101], d[101][101], f[15], c[15][15], dp[1 << 15][15];
char a[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void bfs(int u, int v, int p){
	fo(i, 1, n) fo(j, 1, m) d[i][j] = 1e9;
	rep(i, s) if(i != p) c[p][i] = 1e9;
	queue<pii> q;
	q.push({u, v});
	d[u][v] = 0;
	while(len(q)){
		auto [i, j] = q.front(); q.pop();
		rep(k, 4){
			int ii = i + dx[k];
			int jj = j + dy[k];
			if(1 <= ii and ii <= n and 1 <= jj and jj <= m and a[ii][jj] != '#'){
				if(mini(d[ii][jj], d[i][j] + 1)){
					if(a[ii][jj] == 'S') c[p][idx[ii][jj]] = d[ii][jj];
					q.push({ii, jj});
				}
			}
		}
	}
	f[p] = d[1][1];
}

inline void LonggVuz(){
	cin >> n >> m >> s;
	int cnt = 0;
	fo(i, 1, n) fo(j, 1, m){
		cin >> a[i][j];
		if(a[i][j] == 'S') idx[i][j] = cnt++;
	}
	fo(i, 1, n) fo(j, 1, m) if(a[i][j] == 'S'){
		bfs(i, j, idx[i][j]);
	}
	rep(i, s) dp[1 << i][i] = f[i];
	int full = mask(s) - 1;
	fo(mask, 1, full) if(one(mask) > 1){
		rep(i, s) if(bit(mask, i)){
			dp[mask][i] = 1e9;
			int pre_mask = mask ^ mask(i);
			rep(j, s) if(bit(pre_mask, j)){
				mini(dp[mask][i], dp[pre_mask][j] + c[j][i]);
			}
		}
	}
	int res = 1e9;
	rep(i, s) mini(res, dp[full][i]);
	cout << (res < 1e9 ? res : -1);
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(false) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
