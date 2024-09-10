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
#define int int64_t
#define ld long double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e4 + 7;

int n, a[5][maxn], f[maxn][20], d[20];
// f[i][j] : tong lon nhat khi xet den cot i o trang thai j
bool bit(int n, int i){
	return (n >> i) & 1; // bit thu i cua n
}

void hehe(){
	for(int i=0; i<15; i++){
		bool ok = 1;
		for(int j=0; j<3; j++){
			if(bit(i, j) && bit(i, j + 1)) ok = 0;
		}d[i] = ok;
	}
}

void solve(){
	ms(f);
	for(int i=1; i<=n; i++){
		for(int mask=0; mask<16; mask++){
			if(d[mask]){
				int sum = 0;
				for(int j=0; j<4; j++){
					if(bit(mask, j)) sum += a[j][i];
				}
				for(int pre_mask=0; pre_mask<16; pre_mask++){
					if(d[pre_mask] && ((pre_mask & mask) == 0)){
						f[i][mask] = max(f[i][mask], f[i-1][pre_mask] + sum);
					}
				}
			}
		}
	}int res = -oo;
	for(int i=0; i<16; i++){
		if(d[i]) res = max(res, f[n][i]);
	}cout << res << el;
}

signed main(){
	LonggVuz();
	
	hehe();
	tc(){
		cin >> n;
		int res = -oo;
		for(int i=0; i<4; i++){
			for(int j=1; j<=n; j++){
				cin >> a[i][j];
				res = max(res, a[i][j]);
			}
		}if(res < 0){
			cout << res << el;
		}else solve();
	}
	
	End();
}