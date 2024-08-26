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

int n, s, a[105], c[105], f[105][1005];
bool kq[105];

void truyVet(int n, int k){
	if(!n) return;
	if(f[n][k] == f[n-1][k]){
		truyVet(n - 1, k);
	}else{
		truyVet(n - 1, k - a[n]);
		kq[n] = 1;
	}
}

signed main(){
	LonggVuz();
	
	cin >> n >> s;
	for(int i=1; i<=n; i++){
		cin >> c[i];
	}
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=s; j++){
			if(j >= a[i]){
				f[i][j] = max(f[i-1][j], f[i-1][j-a[i]] + c[i]);
			}else f[i][j] = f[i-1][j];
		}
	}cout << f[n][s] << el;
	truyVet(n, s);
	for(int i=1; i<=n; i++) cout << kq[i] << ' ';
	
	End();
}