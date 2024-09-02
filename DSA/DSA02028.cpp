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

int n, k, x, ps[25], res, target;

void ql(int pos, int cnt){
	if(cnt == k && pos == n){
		++res; return;
	}
	for(int i=pos+1; i<=n; i++){
		if(ps[i] - ps[pos] == target){
			ql(i, cnt + 1);
		}
	}
}

signed main(){
	LonggVuz();
	
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> x;
		ps[i] = ps[i-1] + x;
	}if(ps[n] % k != 0){
		cout << 0;
	}else{
		target = ps[n] / k;
		ql(0, 0);
		cout << res;
	}
	
	End();
}