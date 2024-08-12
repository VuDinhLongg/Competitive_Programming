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

int n, a[105];

bool dx(){
	int l = 1, r = n;
	while(l < r){
		if(a[l] != a[r]) return 0;
		++l; --r;
	}return 1;
}

void in(){
	for(int i=1; i<=n; i++) cout << a[i] << ' '; cout << el;
}

void ql(int i){
	for(int j=0; j<=1; j++){
		a[i] = j;
		if(i == n){
			if(dx()) in();
		}else ql(i + 1);
		a[i] = -1;
	}
}

signed main(){
	LonggVuz();
	
	cin >> n;
	ql(1);
	
	End();
}