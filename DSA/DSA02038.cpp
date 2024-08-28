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

int n, k, a[20];
vector<vector<int>> kq;
vector<int> v;

void ql(int pos, int id){
	if(id == k){
		kq.pb(v); return;
	}
	for(int i=pos; i<=n; i++){
		v.pb(a[i]);
		ql(i + 1, id + 1);
		v.pop_back();
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		v.clear(); kq.clear();
		cin >> n >> k;
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}sort(a+1, a+n+1);
		ql(1, 0);
		sort(all(kq));
		for(auto &ve : kq){
			for(int &so : ve){
				cout << so << ' ';
			}cout << el;
		}
	}
	
	End();
}	