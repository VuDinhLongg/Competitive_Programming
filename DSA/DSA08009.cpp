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
const int maxn = 2e4 + 7;

int p[maxn];

void solve(int a, int b){
	ms(p, 0);
	queue<int> q;
	q.push(a);
	while(!q.empty()){
		int x = q.front(); q.pop();
		if(x == b) break;
		if(x > 1 && p[x - 1] == 0){
			p[x - 1] = x;
			q.push(x - 1);
		}
		if(x < b && p[x * 2] == 0){
			q.push(x * 2);
			p[x * 2] = x;
		}
	}int res = 0, i = b;
	while(i != a){
		++res;
		i = p[i];
	}cout << res << el;
}

signed main(){
	LonggVuz();
	
	tc(){
		int a, b; cin >> a >> b;
		solve(a, b);
	}
	
	End();
}