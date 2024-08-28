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

int n, p, s, l;
vector<int> a, v;
vector<vector<int>> kq;

bool nt(int n){
	int c = sqrtl(n);
	for(int i=2; i<=c; i++) if(n%i == 0) return 0;
	return n > 1;
}

void ql(int id, int pos, int sum){
	if(id == n && sum == s){
		kq.pb(v); return;
	}
	for(int i=pos; i<l; i++){
		if(sum + a[i] <= s){
			v.pb(a[i]);
			ql(id + 1, i + 1, sum + a[i]);
			v.pop_back();
		}
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		v.clear(); a.clear(); kq.clear();
		cin >> n >> p >> s;
		for(int i=p+1; i<s; i++){
			if(nt(i)) a.pb(i);
		}l = len(a);
		ql(0, 0, 0);
		cout << len(kq) << el;
		for(auto &ve : kq){
			for(int &so : ve){
				cout << so << ' ';
			}cout << el;
		}
	}
	
	End();
}