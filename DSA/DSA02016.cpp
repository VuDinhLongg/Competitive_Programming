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
const int maxn = 1e6 + 7;

int n, res;
bool c[105], d1[105], d2[105];
void ql(int i){
	for(int j=1; j<=n; j++){
		if(!c[j] && !d1[i-j+n] && !d2[i+j-1]){
			c[j] = d1[i-j+n] = d2[i+j-1] = 1;
			if(i == n){
				++res;
			}else ql(i + 1);
			c[j] = d1[i-j+n] = d2[i+j-1] = 0;
		}
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		ms(c, 0); ms(d1, 0); ms(d2, 0);
		res = 0;
		cin >> n;
		ql(1);
		cout << res << el;
	}
	
	End();
}