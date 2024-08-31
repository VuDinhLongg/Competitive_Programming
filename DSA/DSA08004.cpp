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

int dem[30];
void solve(str a, int n, int k){
	ms(dem, 0);
	for(char c : a) ++dem[c - 'A'];
	priority_queue<int> q;
	for(int i=0; i<26; i++){
		if(dem[i] > 0) q.push(dem[i]);
	}
	while(k--){
		if(q.empty()) break;
		int x = q.top(); q.pop();
		--x;
		if(x > 0) q.push(x);
	}int res = 0;
	while(!q.empty()){
		int x = q.top(); q.pop();
		res += x * x;
	}cout << res << el;
}

signed main(){
	LonggVuz();
	
	tc(){
		int k; str a; cin >> k >> a;
		solve(a, len(a), k);
	}
	
	End();
}