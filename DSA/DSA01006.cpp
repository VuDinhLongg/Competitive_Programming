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

int n, r[12], mark[12];

void in(){
	for(int i=1; i<=n; i++){
		cout << r[i];
	}cout << ' ';
}

void run(int pos){
	if(pos == n + 1){
		in(); return;
	}
	for(int i=n; i>=1; i--){
		if(!mark[i]){
			r[pos] = i;
			mark[i] = 1;
			run(pos + 1);
			mark[i] = r[pos] = 0;
		}
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		cin >> n;
		run(1);
		cout << el;
	}
	
	End();
}