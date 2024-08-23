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



signed main(){
	LonggVuz();
	
	tc(){
		queue<int> q;
		int n; cin >> n;
		while(n--){
			int lc; cin >> lc;
			if(lc == 1) cout << len(q) << el;
			else if(lc == 2){
				if(q.empty()) cout << "YES\n";
				else cout << "NO\n";
			}else if(lc == 3){
				int x; cin >> x;
				q.push(x);
			}else if(lc == 4){
				if(!q.empty()) q.pop();
			}else if(lc == 5){
				if(!q.empty()) cout << q.front() << el;
				else cout << "-1\n";
			}else{
				if(!q.empty()) cout << q.back() << el;
				else cout << "-1\n";
			}
		}
	}
	
	End();
}