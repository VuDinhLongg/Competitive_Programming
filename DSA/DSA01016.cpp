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

void ql(int n, vector<int> &v){
	if(n == 0){
		cout << '('; int l = len(v);
		for(int i=0; i<l-1; i++) cout << v[i] << ' ';
		cout << v[l-1] << ") ";
		return;
	}
	for(int i=n; i>=1; i--){
		if(n >= i && (v.empty() || i <= v.back())){
			v.pb(i);
			ql(n - i, v);
			v.pop_back();
		}
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		int n; cin >> n;
		vector<int> v;
		ql(n, v);
		cout << el;
	}
	
	End();
}