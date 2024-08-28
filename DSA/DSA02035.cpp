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

int n, k, x, y, f[10], res = oo;
str a[10];

int num(str s){
	int res = 0;
	for(char c : s){
		res = res * 10 + (c - '0');
	}return res;
}

signed main(){
	LonggVuz();
	
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}str s = string(k, '.');
	for(int i=1; i<=k; i++) f[i] = i;
	do{
		x = -oo; y = oo;
		for(int i=1; i<=n; i++){
			for(int j=0; j<k; j++){
				s[j] = a[i][f[j+1]-1];
			}x = max(x, num(s));
			y = min(y, num(s));
		}res = min(res, x - y);
	}while(next_permutation(f + 1, f + k + 1));
	cout << res;

	End();
}