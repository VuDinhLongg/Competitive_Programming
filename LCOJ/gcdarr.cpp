// https://luyencode.net/problem/gcdarr
// LonggVuz
#include<bits/stdc++.h>
using namespace std;
// Think twice, code once ^.^
void End(){
    cerr << "=> Smoothly Finished! Time taken: ";
    cerr << (0.001 * clock()) << "s" << string(25, '\t');
}
#define Sonic() cin.tie(0) -> sync_with_stdio(0)
#define out(x) return cout << x << el, void()
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
const int mxn = 1e5 + 7;

int n, a[mxn], f[mxn * 4];

int gcd(int a, int b){
	while(b){
		int r = a % b;
		a = b; b = r;
	}return a;
}

void build(int id, int l, int r){
	if(l == r){
		f[id] = a[l]; return;
	}int m = (l + r) / 2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	f[id] = gcd(f[id * 2], f[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v){
	if(r < u or v < l) return oo;
	if(u <= l and r <= v) return f[id];
	int m = (l + r) / 2;
	int left = get(id * 2, l, m, u, v);
	int right = get(id * 2 + 1, m + 1, r, u, v);
	if(left == oo) return right;
	if(right == oo) return left;
	return gcd(left, right);
}

void LonggVuz(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		if(a[i] == 1) out("1 " << i << ' ' << i);
	}build(1, 1, n);
	if(f[1] > 1) out(-1);
	int res = oo, st = 0, en = 0;
	for(int i=1; i<=n; i++){
		int l = i + 1, r = n;
		while(l <= r){
			int m = (l + r) / 2;
			int g = get(1, 1, n, i, m);
			if(g == 1){
				if(m - i + 1 < res){
					res = m - i + 1;
					st = i; en = m;
				}
				r = m - 1;
			}else l = m + 1;
		}
	}cout << res << ' ' << st << ' ' << en;
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
