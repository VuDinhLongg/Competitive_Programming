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
#define ms(x) memset(x, 0, sizeof(x))
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

int n, s, a[22], ok;

void ql(int pos, int sum, vector<int> v){
	if(sum == s){
		int l = len(v);
		cout << "[";
		for(int i=0; i<l-1; i++) cout << v[i] << ' ';
		cout << v[l-1] << "]";
		ok = 1; return;
	}
	for(int i=pos; i<=n; i++){
		if(sum + a[i] <= s){
			v.pb(a[i]);
			ql(i, sum + a[i], v);
			v.pop_back();
		}
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		cin >> n >> s; ok = 0;
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}sort(a+1, a+n+1);
		vector<int> v;
		ql(1, 0, v);
		if(!ok) cout << -1;
		cout << el;
	}
	
	End();
}