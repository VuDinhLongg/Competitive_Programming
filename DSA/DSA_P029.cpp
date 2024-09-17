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
const int maxn = 5e4 + 7;

int n, a[16][16], f[maxn][16];
// f[i][j] : chi phí nhỏ nhất để đạt được trạng thái i khi kết thúc tại thành phố j
bool bit(int x, int i){
	return (x >> i) & 1; // bit thứ i của số x
}

int cnt(int x){ // đếm số bit 1 trong số x
	int ans = 0;
	while(x){
		ans += x % 2;
		x /= 2;
	}return ans;
}

void LonggVuz(){
	ms(f);
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) cin >> a[i][j];
	int x = 1 << n;
	for(int mask=1; mask<x; mask++){
		if(cnt(mask) > 1){
			for(int i=0; i<n; i++){
				if(bit(mask, i)){
					int pre_mask = mask - (1 << i);
					f[mask][i] = oo;
					for(int j=0; j<n; j++){
						if(bit(pre_mask, j)){
							f[mask][i] = min(f[mask][i], f[pre_mask][j] + a[j][i]);
						}
					}
				}
			}
		}
	}int res = oo;
	for(int i=0; i<n; i++){
		res = min(res, f[x-1][i]);
	}cout << res << el;
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
