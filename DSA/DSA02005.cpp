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

int n;
str a, s;
bool mark[15];

void ql(){
	for(int i=0; i<n; i++){
		if(!mark[i]){
			mark[i] = 1;
			s.pb(a[i]);
			if(len(s) == n){
				cout << s << ' ';
			}else ql();
			s.pop_back();
			mark[i] = 0;
		}
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		cin >> a; n = len(a);
		ql(); cout << el;
	}
	
	End();
}