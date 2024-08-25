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
#define pii pair<int, int>

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

vector<int> v[50];

signed main(){
	LonggVuz();
	
	int n, x; cin >> n;
	for(int i=1; i<=n; i++){
		str a; getline(cin >> ws, a);
		stringstream ss(a);
		while(ss >> x) v[i].pb(x);
	}
	for(int i=1; i<=n; i++){
		for(int &j : v[i]){
			if(j > i){
				cout << i << ' ' << j << el;
			}
		}
	}
	
	End();
}