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
#define all(x) begin(x), end(x)
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
const int mxn = 1e6 + 7;

struct canh{
	int u, v, w;
};

int n, m, p[105];
vector<canh> v;

int get(int u){
	if(u == p[u]) return u;
	return p[u] = get(p[u]);
}

bool cmp(canh a, canh b){
	return a.w < b.w;
}

void LonggVuz(){
	cin >> n >> m;
	for(int i=1; i<=n; i++) p[i] = i;
	while(m--){
		int x, y, w;
		cin >> x >> y >> w;
		v.pb({x, y, w});
	}
	sort(all(v), cmp);
	int mst = 0, sz = 0, i = 0;
	while(sz < n - 1 and i < len(v)){
		canh d = v[i++];
		int x = get(d.u), y = get(d.v);
		if(x == y) continue;
		p[y] = x;
		++sz;
		mst += d.w;
	}
	cout << mst << el;
	v.clear();
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}