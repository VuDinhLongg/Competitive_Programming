/*
    vudinhlong 1:17:41 sa, 16/12/2024
    => Old style, update later... :D
*/

// LonggVuz
#include<bits/stdc++.h>
using namespace std;
// ☞ Think twice, code once ☜
void End(){
    cerr << "=> Smoothly Finished! Time taken: ";
    cerr << (0.001 * clock()) << "s" << string(25, '\t');
}
#define Sonic() cin.tie(0) -> sync_with_stdio(0)
#define out(x) return cout << x, void()
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define pb push_back
#define is insert
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 2e5 + 7;

#define pe pair<int, int>
#define fi first
#define se second
int n, c, d[mxn], t[mxn], f[mxn * 4];
pe a[mxn];

void build(int id, int l, int r){
	if(l == r){
		f[id] = d[l]; return;
	}
	int m = (l + r) / 2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	f[id] = max(f[id * 2], f[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v){
	if(r < u or v < l) return -oo;
	if(u <= l and r <= v) return f[id];
	int m = (l + r) / 2;
	return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

void LonggVuz(){
	cin >> n >> c;
	for(int i=1; i<=n; i++){
		cin >> a[i].fi;
	}
	for(int i=1; i<=n; i++){
		cin >> a[i].se;
	}
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++){
		if(i < n) d[i] = a[i + 1].fi - a[i].fi;
		t[i] = t[i - 1] + a[i].se;
	}
	build(1, 1, n - 1);
	int res = oo;
	for(int i=1; i<=n; i++){
		int j = lower_bound(t+i, t+n+1, t[i - 1] + c) - t;
		if(j == n + 1) break;
		if(j == i){
			res = min(res, d[i]);
			continue;
		}
		int mx = get(1, 1, n - 1, i, j - 1);
		if(mx > -oo) res = min(res, mx);
	}cout << res;
}

signed main(){
	Sonic();
	
	signed test = 1;
	//cin >> test;
	for(signed i=1; i<=test; i++){
		LonggVuz();
	}
	
	End();
}
