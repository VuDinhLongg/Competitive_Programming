// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Noob C++
void End(){
    cerr << "=> Thời gian code chạy: ";
    cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define Sonic() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define ms(x) memset(x, 0, sizeof(x))
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define str string
#define int int64_t
#define ld long double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

struct cv{
	int id, dl, pr;
};

bool used[1005];
bool cmp(cv a, cv b){
	return a.pr > b.pr;
}

void LonggVuz(){
	ms(used);
	int n; cin >> n;
	cv a[n+5];
	for(int i=1; i<=n; i++){
		cin >> a[i].id >> a[i].dl >> a[i].pr;
	}sort(a+1, a+n+1, cmp);
	int res = 0, cnt = 0;
	for(int i=1; i<=n; i++){
		int dl = a[i].dl;
		int pr = a[i].pr;
		for(int j=dl; j>=1; j--){
			if(!used[j]){
				++cnt; res += pr;
				used[j] = 1; break;
			}
		}
	}cout << cnt << ' ' << res << el;
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
