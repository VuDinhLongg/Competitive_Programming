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

int n, k;
struct matrix{
	int x[5][5];
	matrix(){
		ms(x, 0);
	}
};

matrix operator * (const matrix &a, const matrix &b){
	matrix r;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				r.x[i][j] += a.x[i][k] * b.x[k][j];
				r.x[i][j] %= mod;
			}
		}
	}return r;
}

matrix mu(matrix &t, int k){
	if(k == 0){
		matrix dvi;
		for(int i=0; i<n; i++) dvi.x[i][i] = 1;
		return dvi;
	}matrix tmp = mu(t, k / 2);
	tmp = tmp * tmp;
	if(k % 2) tmp = tmp * t;
	return tmp;
}

signed main(){
	LonggVuz();
	
	tc(){
		cin >> n >> k;
		matrix t;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> t.x[i][j];
			}
		}t = mu(t, k);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout << t.x[i][j] << ' ';
			}cout << el;
		}
	}
	
	End();
}