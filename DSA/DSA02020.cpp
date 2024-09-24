// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Legendary Grandmaster
void End(){
    cerr << "=> Thời gian code chạy: ";
    cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define Sonic() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define ms(a, x) memset(a, x, sizeof(a))
#define bit(n, x) (n >> x & 1)
#define pb push_back
#define is insert
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int res, c, p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

void ql(int n, vector<int> &a){
	if(n < 60){
		int ans = 1, id = 0;
		vector<int> t = a;
		t.push_back(n);
		reverse(all(t));
		for(int &i : t){
			while(--i) ans *= p[id];
			++id;
		}if(ans > 0) res = min(res, ans);
		if(n == 1) return;
	}
	for(int i=2; i<=c; i++){
		if(n%i == 0){
			a.push_back(i);
			ql(n / i, a);
			a.pop_back();
		}
	}
}

void LonggVuz(){
	int n; cin >> n;
	if(n == 1) return cout << "1\n", void();
	res = oo; c = sqrtl(n);
	vector<int> a;
	ql(n, a);
	cout << res << el;
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}