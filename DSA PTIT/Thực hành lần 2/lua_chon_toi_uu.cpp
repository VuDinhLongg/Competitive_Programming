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

struct pe{
	int x, y;
};

bool cmp(pe a, pe b){
	if(a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

void LonggVuz(){
	int n; cin >> n;
	pe a[n+5];
	for(int i=1; i<=n; i++){
		cin >> a[i].x >> a[i].y;
	}sort(a+1, a+n+1, cmp);
	int res = 1;
	pe p = a[1];
	for(int i=2; i<=n; i++){
		if(a[i].x >= p.y){
			++res;
			p.y = a[i].y;
		}
	}cout << res << el;
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
