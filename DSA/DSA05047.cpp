// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Noob C++
void End(){
    cerr << "=> Thời gian code chạy: ";
    cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define Sonic() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define ms(x) memset(x, 0, sizeof(x))
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
// f[i][j] : tổng lớn nhất khi xét đến cột i ở trạng thái j
// d[i] = 1 -> trạng thái i là thoả mãn, ngược lại là ko thoả mãn
bool bit(int n, int i){
	return (n >> i) & 1; // bit thứ i của số n
}

void hehe(){
	for(int i=0; i<15; i++){
		bool ok = 1;
		for(int j=0; j<3; j++){
			if(bit(i, j) && bit(i, j + 1)){
				ok = 0; break;
			}
		}d[i] = ok;
	}
}

void LonggVuz(){
	int mx = -oo;
	cin >> n;
	for(int i=0; i<4; i++){
		for(int j=1; j<=n; j++){
			cin >> a[i][j];
			mx = max(mx, a[i][j]);
		}
	}if(mx <= 0) return cout << mx << el, void();
	ms(f);
	for(int i=1; i<=n; i++){
		for(int mask=0; mask<15; mask++){
			if(d[mask]){
				int sum = 0;
				for(int j=0; j<4; j++){
					if(bit(mask, j)) sum += a[j][i];
				}f[i][mask] = -oo;
				for(int pre_mask=0; pre_mask<15; pre_mask++){
					if(d[pre_mask] && (mask & pre_mask) == 0){
						f[i][mask] = max(f[i][mask], f[i-1][pre_mask] + sum);
					}
				}
			}
		}
	}int res = -oo;
	for(int i=0; i<15; i++){
		if(d[i]) res = max(res, f[n][i]);
	}cout << res << el;
}

signed main(){
	Sonic();
	
	hehe();
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
