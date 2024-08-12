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

int n, a[22];
vector<int> v;
vector<vector<int>> kq;

bool cmp(vector<int> a, vector<int> b){
	str u = "", v = "";
	for(int &i : a) u += to_string(i) + " ";
	for(int &i : b) v += to_string(i) + " ";
	return u < v;
}

void ql(int pos){
	for(int i=pos; i<=n; i++){
		if(v.empty() || a[i] > v.back()){
			v.pb(a[i]);
			if(len(v) > 1) kq.pb(v);
			ql(i + 1);
			v.pop_back();
		}
	}
}

signed main(){
	LonggVuz();
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}ql(1);
	sort(all(kq), cmp);
	for(auto &i : kq){
		for(int &j : i){
			cout << j << ' ';
		}cout << el;
	}
	
	End();
}