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

int n, k, p[50];
str a[50], s;
vector<str> kq, v;

void ql(int i){
	for(int j=p[i-1]+1; j<=n; j++){
		p[i] = j;
		if(i == k){
			s = "";
			for(int x=1; x<=k; x++){
				s += v[p[x]];
				s += " ";
			}kq.pb(s);
		}else ql(i + 1);
		p[i] = -1;
	}
}

signed main(){
	LonggVuz();
	
	cin >> n >> k; v.pb("");
	for(int i=1; i<=n; i++){
		cin >> a[i];
		bool tm = 1;
		for(auto &j : v){
			if(a[i] == j){
				tm = 0; break;
			}
		}if(tm) v.pb(a[i]);
	}sort(all(v)); n = len(v) - 1; 
	ql(1);
	for(auto &i : kq) cout << i << el;
	
	End();
}