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

int n; char c;
str a;
bool mark[300];

void ql(int i){
	for(int j='1'; j<=c; j++){
		if(!mark[j] && abs(j - a.back()) != 1){
			mark[j] = 1;
			a.pb(j);
			if(i == n){
				cout << a << el;
			}else ql(i + 1);
			mark[j] = 0;
			a.pop_back();
		}
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		a = ""; ms(mark, 0);
		cin >> n; c = n + '0';
		ql(1);
	}
	
	End();
}