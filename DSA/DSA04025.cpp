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

struct matrix{
	int x[3][3];
	matrix(){ // constructor
		ms(x, 0);
	}
};

matrix operator * (const matrix &a, const matrix &b){
	matrix c;
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			for(int k=0; k<2; k++){
				c.x[i][j] += a.x[i][k] * b.x[k][j];
				c.x[i][j] %= mod;
			}
		}
	}return c;
}

matrix mu(const matrix &t, int n){
	if(!n){
		matrix dvi;
		for(int i=0; i<2; i++) dvi.x[i][i] = 1;
		return dvi;
	}
	matrix tmp;
	tmp = mu(t, n / 2);
	tmp = tmp * tmp;
	if(n%2) tmp = tmp * t;
	return tmp;
}

signed main(){
	LonggVuz();
	
	tc(){
		int n; cin >> n;
		if(n < 2){
			cout << n << el; continue;
		}matrix t;
		t.x[0][0] = t.x[0][1] = t.x[1][0] = 1;
		t = mu(t, n - 1);
		cout << t.x[0][0] << el;
	}
	
	End();
}