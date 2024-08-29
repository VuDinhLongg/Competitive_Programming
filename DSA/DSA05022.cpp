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
#define int intmax_t
#define ld long double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int f[123]; // f[i] : min thao tac de ghi ra i ky tu

signed main(){
	LonggVuz();
	
	tc(){
		int n, x, y, z; cin >> n >> x >> y >> z;
		f[1] = x;
		for(int i=2; i<=105; i++){
			f[i] = f[i-1] + x;
			if(i%2 == 0) f[i] = min(f[i], f[i/2] + z);
			for(int j=i-1; j>=2; j--){
				f[j] = min(f[j], f[i] + y * (i - j));
			}
		}cout << f[n] << el;
	}
	
	End();
}