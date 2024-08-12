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

int n, a[15], mark[15];
vector<int> v;

void in(){
	for(int i : v){
		cout << a[i] << ' ';
	}cout << el;
}

void ql(int i){
	for(int j=1; j<=n; j++){
		if(!mark[j]){
			mark[j] = 1;
			v.pb(j);
			if(i == n){
				in();
			}else ql(i + 1);
			v.pop_back();
			mark[j] = 0;
		}
	}
}

signed main(){
	LonggVuz();
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}sort(a+1, a+n+1);
	ql(1);
	
	End();
}