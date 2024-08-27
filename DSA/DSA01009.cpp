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

int n, k;
vector<str> v;
str s;

bool check(){
	for(int i=0; i<n; i++){
		if(s[i] == 'A' && (!i || s[i-1] == 'B')){
			int len = 1;
			for(int j=i+1; j<n; j++){
				if(s[j] == 'A') ++len;
				else break;
			}if(len == k) return 1;
		}
	}return 0;
}

void ql(){
	for(char i='A'; i<='B'; i++){
		s.pb(i);
		if(len(s) == n){
			if(check()) v.pb(s);
		}else ql();
		s.pop_back();
	}
}

signed main(){
	LonggVuz();
	
	cin >> n >> k;
	ql();
	cout << len(v) << el;
	for(auto &i : v) cout << i << el;
	
	End();
}