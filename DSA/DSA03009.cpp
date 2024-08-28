// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Noob C++
void End(){
    cerr << "\n\n=> Thời gian code chạy: ";
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

struct cv{
	int id, x, y;
};

bool w[1005];
bool cmp(cv a, cv b){
	return a.y > b.y;
}

signed main(){
	LonggVuz();
	
	tc(){
		ms(w, 0);
		int n; cin >> n;
		cv a[n+5];
		for(int i=0; i<n; i++){
			cin >> a[i].id >> a[i].x >> a[i].y;
		}sort(a, a + n, cmp);
		int res = 0, cnt = 0;
		for(int i=0; i<n; i++){
			for(int j=min(n, a[i].x); j>=1; j--){
				if(!w[j]){
					w[j] = 1;
					res += a[i].y;
					++cnt; break;
				}
			}
		}cout << cnt << ' ' << res << el;
	}
	
	End();
}