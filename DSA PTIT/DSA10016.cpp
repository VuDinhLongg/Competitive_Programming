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
#define pe pair<ld, ld>
#define fi first
#define se second

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

struct canh{
	int u, v;
	ld w;
};

int n, p[105];
vector<canh> v;

int get(int u){
	if(u == p[u]) return u;
	return p[u] = get(p[u]);
}

ld dis(pe a, pe b){
	return sqrtl((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}

bool cmp(canh a, canh b){
	return a.w < b.w;
}

void LonggVuz(){
	cin >> n;
	pe a[n+5];
	for(int i=1; i<=n; i++){
		p[i] = i;
	}
	for(int i=1; i<=n; i++){
		cin >> a[i].fi >> a[i].se;
	}
	for(int i=1; i<n; i++){
		for(int j=i+1; j<=n; j++){
			v.pb({i, j, dis(a[i], a[j])});
		}
	}
	sort(all(v), cmp);
	ld mst = 0;
	int sz = 0, i = 0;
	while(sz < n - 1 and i < len(v)){
		canh c = v[i++];
		int x = get(c.u), y = get(c.v);
		if(x == y) continue;
		p[y] = x;
		mst += c.w;
		++sz;
	}
	cout << fix(6) << mst << el;
	v.clear();
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}