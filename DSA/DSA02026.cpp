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

bool ok;
str a, dau = "+-*/";

bool check(){
	int x = (a[0] - '0') * 10 + (a[1] - '0');
	int y = (a[5] - '0') * 10 + (a[6] - '0');
	int z = (a[10] - '0') * 10 + (a[11]  - '0');
	if(a[3] == '+'){
		if(x + y == z) return 1;
	}else if(a[3] == '-'){
		if(x - y == z) return 1;
	}else if(a[3] == '*'){
		if(x * y == z) return 1;
	}else{
		if(x % y == 0 && x / y == z) return 1;
	}return 0;
}

void ql(int i){
	if(i == 12){
		if(check()){
			cout << a << el;
			ok = 1;
		}return;
	}
	if(i == 2 || i == 4 || i == 7 || i == 8 || i == 9 || a[i] != '?'){
		ql(i + 1); return;
	}
	if(i == 0 || i == 5 || i == 10){
		for(char j='1'; j<='9'; j++){
			a[i] = j;
			ql(i + 1); if(ok) return;
			a[i] = '?';
		}
	}else if(i == 1 || i == 6 || i == 11){
		for(char j='0'; j<='9'; j++){
			a[i] = j;
			ql(i + 1); if(ok) return;
			a[i] = '?';
		}
	}else if(i == 3){
		for(char c : dau){
			a[i] = c;
			ql(i + 1); if(ok) return;
			a[i] = '?';
		}
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		ok = 0;
		getline(cin >> ws, a);
		ql(0);
		if(!ok) cout << "WRONG PROBLEM!\n";
	}
	
	End();
}