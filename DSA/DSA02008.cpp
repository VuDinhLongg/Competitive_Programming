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

int n, k, a[15][15];
vector<vector<int>> kq;
vector<int> v;
bool mark[15];

void ql(int h, int sum){
	if(h == n + 1){
		if(sum == k) kq.pb(v);
		return;
	}
	for(int i=1; i<=n; i++){
		if(!mark[i] && sum + a[h][i] <= k){
			mark[i] = 1;
			v.pb(i);
			ql(h + 1, sum + a[h][i]);
			v.pop_back();
			mark[i] = 0;
		}
	}
}

signed main(){
	LonggVuz();
	
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> a[i][j];
		}
	}ql(1, 0);
	cout << len(kq) << el;
	for(auto &ve : kq){
		for(int &so : ve){
			cout << so << ' ';
		}cout << el;
	}
	
	End();
}