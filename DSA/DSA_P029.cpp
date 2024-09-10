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
#define int int32_t
#define ld long double

const int mod = 1e9 + 7;
const int oo = 1e9 + 7;
const int maxn = 1e6 + 7;

int n, c[20][20], f[1 << 17][20];
// f[i][j] : chi phi de dat duoc trang thai i khi ket thuc tai thanh pho j
bool bit(int n, int i){
	return (n >> i) & 1; // bit thu i cua n
}

void solve(){
	ms(f);
	int x = 1 << n;
	for(int mask=1; mask<x; mask++){
		if(__builtin_popcount(mask) > 1){
			for(int i=0; i<n; i++){
				if(bit(mask, i)){
					f[mask][i] = oo;
					int pre_mask = mask - (1 << i);
					for(int j=0; j<n; j++){
						if(bit(pre_mask, j)){
							f[mask][i] = min(f[mask][i], f[pre_mask][j] + c[j][i]);
						}
					}
				}
			}
		}
	}int res = oo;
	for(int i=0; i<n; i++){
		res = min(res, f[(1 << n) - 1][i]);
	}cout << res << el;
}

signed main(){
	LonggVuz();
	
	tc(){
		cin >> n;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> c[i][j];
			}
		}solve();
	}
	
	End();
}