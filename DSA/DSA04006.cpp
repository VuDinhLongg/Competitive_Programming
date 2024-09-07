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
#define int intmax_t
#define ld long double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int end(int n){
	if(n <= 1) return 1;
	return 2 * end(n / 2) + 1;
}

int cal(int n, int l, int r, int u, int v){
	if(n == 1){
		if(l <= u && v <= r) return 1;
		return 0;
	}int res = 0;
	int mid = (u + v) / 2;
	if(l < mid) res += cal(n / 2, l, r, u, mid - 1);
	if(mid < r) res += cal(n / 2, l, r, mid + 1, v);
	if(l <= mid && mid <= r) res += n % 2;
	return res;
}

signed main(){
	LonggVuz();
	
	tc(){
		int n, l, r; cin >> n >> l >> r;
		cout << cal(n, l, r, 1, end(n)) << el;
	}
	
	End();
}