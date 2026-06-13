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
#define fix(x) fixed << setprecision(x)
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 1007
#define ai3 array<int, 3>
#define ai4 array<int, 4>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, p, q, a[mxn][mxn], b[mxn][mxn], cnt[mxn * mxn];

inline void LonggVuz(){
	cin >> n >> m >> p;
    rep(tt, p){
    	int x, y, z, t, c; cin >> x >> y >> z >> t >> c;
    	int val = (1ll << c);
    	a[x][y] += val;
    	b[x][y] += 1;
    	a[z + 1][y] -= val;
    	b[z + 1][y] -= 1;
    	a[x][t + 1] -= val;
    	b[x][t + 1] -= 1;
    	a[z + 1][t + 1] += val;
    	b[z + 1][t + 1] += 1;
    }
    fo(i, 1, n) fo(j, 1, n){
    	a[i][j] += a[i][j - 1];
    	b[i][j] += b[i][j - 1];
    }
    fo(j, 1, n) fo(i, 1, n){
    	a[i][j] += a[i - 1][j];
    	b[i][j] += b[i - 1][j];
    }
    vector<pii> zip;
    fo(i, 1, n) fo(j, 1, n){
		zip.push_back({a[i][j], b[i][j]});
		// debug(i, j, a[i][j]);
	}
	sort(all(zip));
	zip.erase(unique(all(zip)), end(zip));
	fo(i, 1, n) fo(j, 1, n){
		a[i][j] = lower_bound(all(zip), make_pair(a[i][j], b[i][j])) - begin(zip) + 1;
		++cnt[a[i][j]];
	}
    cin >> q;
    while(q--){
    	int u, v; cin >> u >> v;
    	cout << cnt[a[u][v]], el;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}