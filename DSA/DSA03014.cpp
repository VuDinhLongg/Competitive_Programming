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

int n, res, t[maxn];
str a;

void hehe(){
	for(int i=1; i<=1e6; i++) t[i] = i * i * i;
}

bool check(int x){
	return binary_search(t + 1, t + 1000001, x);
}

void ql(int pos, int x){
	if(x){
		if(check(x)) res = max(res, x);
	}
	for(int i=pos; i<n; i++){
		x = x * 10 + (a[i] - '0');
		ql(i + 1, x);
		x = (x - (a[i] - '0')) / 10;
	}
}

signed main(){
	LonggVuz();
	
	hehe();
	tc(){
		res = -oo;
		cin >> a; n = len(a);
		ql(0, 0);
		if(res != -oo){
			cout << res << el;
		}else cout << "-1\n";
	}
	
	End();
}