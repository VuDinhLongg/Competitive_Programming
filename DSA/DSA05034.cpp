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
#define db double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e5 + 7;

int f[maxn];
int val(int n, int k){
	ms(f, 0);
	f[1] = 1; f[k+1] = 1; 
	for(int i=2; i<=k; i++){
		f[i] = f[i-1] * 2;
		f[i] %= mod;
		f[k+1] += f[i];
	}f[k+1] %= mod;
	for(int i=k+2; i<=n; i++){
		f[i] = f[i-1] + f[i-1] - f[i-k-1];
		f[i] = (f[i] + mod) % mod;
	}return f[n];
}

signed main(){
	LonggVuz();
	
	tc(){
		int n, k;
		cin >> n >> k;
		cout << val(n, k) << el;
	}
	
	End();
}