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
str a = "8";

bool check(){
	for(int i=0; i<n-1; i++){
		if(a[i] == '8' && a[i+1] == '8') return 0;
		if(i < n - 3 && a[i] == '6'){
			int cnt = 1;
			for(int j=i+1; j<n; j++){
				if(a[j] == '6') ++cnt;
				else break;
			}if(cnt > 3) return 0;
		}
	}return 1;
}

void ql(){
	for(int i='6'; i<='8'; i+=2){
		a.pb(i);
		if(len(a) + 1 == n){
			a.pb('6');
			if(check()) cout << a << el;
			a.pop_back();
		}else ql();
		a.pop_back();
	}
}

signed main(){
	LonggVuz();
	
	cin >> n;
	ql();
	
	End();
}