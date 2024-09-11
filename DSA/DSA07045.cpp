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
#define int int64_t
#define ld long double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;



signed main(){
	LonggVuz();
	
	str a; cin >> a;
	int n = len(a);
	stack<char> l, r;
	for(int i=0; i<n; i++){
		if(a[i] == '<'){
			if(l.empty()) continue;
			char c = l.top(); l.pop();
			r.push(c);
		}else if(a[i] == '>'){
			if(r.empty()) continue;
			char c = r.top(); r.pop();
			l.push(c);
		}else if(a[i] == '-'){
			if(!l.empty()) l.pop();
		}else l.push(a[i]);
	}str res = "";
	while(!l.empty()){
		res.pb(l.top()); l.pop();
	}reverse(all(res));
	while(!r.empty()){
		res.pb(r.top()); r.pop();
	}cout << res;
	
	End();
}