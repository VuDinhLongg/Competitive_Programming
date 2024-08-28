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
#define int uintmax_t
#define ld long double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int mu(int a, int b){
	int res = 1;
	while(b){
		if(b%2) res *= a;
		b /= 2; a *= a;
	}return res;
}

int cal(str a, str b){
	reverse(all(a)); reverse(all(b));
	int x = 0, y = 0, n = len(a), m = len(b);
	for(int i=0; i<n; i++){
		if(a[i] == '1') x += mu(2, i);
	}
	for(int i=0; i<m; i++){
		if(b[i] == '1') y += mu(2, i);
	}return x * y;
}

signed main(){
	LonggVuz();
	
	tc(){
		str a, b; cin >> a >> b;
		cout << cal(a, b) << el;
	}
	
	End();
}