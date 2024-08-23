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

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

void solve(int n){
	queue<int> q;
	queue<str> r;
	q.push(9);
	r.push("9");
	while(!q.empty()){
		int tmp = q.front(); q.pop();
		str s = r.front(); r.pop();
		if(tmp % n == 0){
			cout << s << el; return;
		}
		q.push((tmp * 10) % n); q.push((tmp * 10 + 9) % n);
		r.push(s + "0"); r.push(s + "9");
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		int n; cin >> n;
		solve(n);
	}
	
	End();
}