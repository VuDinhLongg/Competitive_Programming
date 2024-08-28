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

int k, n, l;
str a, res;
vector<pii> v;

void ql(int pos, int id){
	for(int i=pos; i<l; i++){
		swap(a[v[i].fi], a[v[i].se]);
		res = max(res, a);
		if(id + 1 <= k) ql(i + 1, id + 1);
		swap(a[v[i].fi], a[v[i].se]);
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		v.clear();
		cin >> k >> a;
		res = a;
		if(k == 0){
			cout << a << el;
		}else{
			n = len(a);
			for(int i=0; i<n; i++){
				for(int j=i+1; j<n; j++){
					v.pb({i, j});
				}
			}l = len(v);
			ql(0, 1);
			cout << res << el;
		}
	}
	
	End();
}