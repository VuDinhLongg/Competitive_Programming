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
char c;
str a;
bool m[105];

bool check(){
	for(int i=1; i<n-1; i++){
		if(a[i] == 'A' || a[i] == 'E'){
			if(a[i-1] != 'A' && a[i-1] != 'E' && a[i+1] != 'A' && a[i+1] != 'E') return 0;
		}
	}return 1;
}

void ql(){
	for(char i='A'; i<=c; i++){
		if(!m[i]){
			m[i] = 1;
			a.pb(i);
			if(len(a) == n){
				if(check()) cout << a << el;
			}else ql();
			a.pop_back();
			m[i] = 0;
		}
	}
}

signed main(){
	LonggVuz();
	
	cin >> c; n = c - 'A' + 1;
	ql();
	
	End();
}