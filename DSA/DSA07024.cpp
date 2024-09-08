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
const int maxn = 1e5 + 7;

int l[maxn], r[maxn];
// l[i] : lưu chỉ số của số đầu tiên bên trái < a[i]
// r[i] : lưu chỉ số của số đầu tiên bên phải < a[i]

void solve(int a[], int n){
	stack<int> st1;
	st1.push(1);
	l[1] = 0;
	for(int i=2; i<=n; i++){
		while(!st1.empty() && a[i] <= a[st1.top()]){
			st1.pop();
		}if(st1.empty()){
			l[i] = 0;
		}else l[i] = st1.top();
		st1.push(i);
	}
	stack<int> st2;
	st2.push(n);
	r[n] = n + 1;
	for(int i=n-1; i>=1; i--){
		while(!st2.empty() && a[i] <= a[st2.top()]){
			st2.pop();
		}if(st2.empty()){
			r[i] = n + 1;
		}else r[i] = st2.top();
		st2.push(i);
	}int res = 0;
	for(int i=1; i<=n; i++){
		int x = l[i] + 1;
		int y = r[i] - 1;
		if(y - x + 1 >= a[i]) res = max(res, a[i]);
	}cout << res << el;
}

signed main(){
	LonggVuz();
	
	tc(){
		int n; cin >> n;
		int a[n+5];
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}solve(a, n);
	}
	
	End();
}