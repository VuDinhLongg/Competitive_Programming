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
#define db double

int n, k, a[105], mark[105];
vector<vector<int>> kq;
vector<int> v;

void ql(int pos, int sum){
	if(sum == k){
		kq.pb(v); return;
	}
	for(int i=pos; i<=n; i++){
		if(!mark[i] && sum + a[i] <= k){
			mark[i] = 1;
			v.pb(a[i]);
			ql(i + 1, sum + a[i]);
			v.pop_back();
			mark[i] = 0;
		}
	}
}

signed main(){
	LonggVuz();
	
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	ql(1, 0);
	sort(all(kq), greater<vector<int>>());
	for(auto &i : kq){
		for(int &j : i){
			cout << j << ' ';
		}cout << el;
	}cout << len(kq);
	
	End();
}