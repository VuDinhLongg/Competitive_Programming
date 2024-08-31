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

int n, k, a[22], sum, ok;
bool mark[22];
void ql(int pos, int x, int cnt){
	if(x == sum){
		if(cnt == k){
			ok = 1; return;
		}
		ql(1, 0, cnt + 1);
		return;
	}
	for(int i=pos; i<=n; i++){
		if(!mark[i] && x + a[i] <= sum){
			ql(i + 1, x + a[i], cnt);
			if(ok) return;
		}
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		cin >> n >> k;
		sum = 0; ms(mark, 0);
		for(int i=1; i<=n; i++){
			cin >> a[i];
			sum += a[i];
		}if(sum % k){
			cout << "0\n";
		}else{
			sum /= k; ok = 0;
			ql(1, 0, 1);
			cout << ok << el;
		}
	}
	
	End();
}