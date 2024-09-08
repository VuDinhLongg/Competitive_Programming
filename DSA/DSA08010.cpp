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
#define ms(x) memset(x, 0, sizeof(x))
#define tc() int TC; cin >> TC; while(TC--)
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define str string
#define int int32_t
#define ld long double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

unordered_map<int, int> f;

int cal(int n){
	f.clear();
	queue<int> q;
	q.push(n);
	while(!q.empty()){
		int x = q.front(); q.pop();
		if(x == 1) return f[x];
		if(f[x - 1] == 0){
			q.push(x - 1);
			f[x - 1] = f[x] + 1;
		}int c = sqrtl(x);
		for(int i=c; i>=2; i--){
			if(x % i == 0 && f[x / i] == 0){
				q.push(x / i);
				f[x / i] = f[x] + 1;
			}
		}
	}return 0;
}

signed main(){
	LonggVuz();
	
	tc(){
		int n; cin >> n;
		cout << cal(n) << el;
	}
	
	End();
}