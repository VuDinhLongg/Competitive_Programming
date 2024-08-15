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

int Min(str a, str b){
	for(char &c : a){
		if(c == '6') c = '5';
	}
	for(char &c : b){
		if(c == '6') c = '5';
	}return stoll(a) + stoll(b);
}

int Max(str a, str b){
	for(char &c : a){
		if(c == '5') c = '6';
	}
	for(char &c : b){
		if(c == '5') c = '6';
	}return stoll(a) + stoll(b);
}

signed main(){
	LonggVuz();
	
	str a, b; cin >> a >> b;
	cout << Min(a, b) << ' ' << Max(a, b);
	
	End();
}