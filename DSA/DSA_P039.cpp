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
#define ms(a, x) memset(a, x, sizeof(a))
#define tc() int TC; cin >> TC; while(TC--)
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define str string
#define int int32_t
#define db double

const int mod = 1e9 + 7;
const int oo = 1e9 + 7;
const int maxn = 2e6 + 7;

int n, a[22][22], f[22][maxn];
// f[i][j] : tong lon nhat khi bat dau tu hang i
// voi trang thai j (trang thai o hang i - 1)
bool bit(int n, int i){
	return (n >> i) & 1;
}

int cal(int i, int j){
	if(i > n) return 0;
	if(f[i][j] > 0) return f[i][j];
	int row = 1 << (n - 1), mx = -oo;
	for(int c=1; c<=n; c++){
		if((j & row) == 0){
			int cur = j | row;
			mx = max(mx, cal(i + 1, cur) + a[i][c]);
		}row = row >> 1;
	}f[i][j] = mx;
	return mx;
}

signed main(){
	LonggVuz();
	
	tc(){
		ms(f, 0);
		cin >> n;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				cin >> a[i][j];
			}
		}cout << cal(1, 0) << el;
	}
	
	End();
}