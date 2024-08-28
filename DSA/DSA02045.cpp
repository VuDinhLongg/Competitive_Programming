// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Noob C++
void End(){
    cerr << "\n\n=> Thời gian code chạy: ";
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
const int maxn = 1e5 + 7;

int n;
str a, s;

void ql(int pos){
	if(len(s)){
		cout << s << " ";
	}
	for(int i=pos; i<n; i++){
		s.pb(a[i]);
		ql(i + 1);
		s.pop_back();
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		s = "";
		cin >> n >> a;
		sort(all(a));
		ql(0);
		cout << el;
	}
	
	End();
}