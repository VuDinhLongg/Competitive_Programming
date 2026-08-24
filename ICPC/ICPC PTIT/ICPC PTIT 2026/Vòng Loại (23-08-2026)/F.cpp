#include <bits/stdc++.h>
using namespace std;

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define len(x) (int)x.size()
#define int long long
#define mxn 500'007

const int mod = 998244853;

array<vector<int>, 2> fbase;
array<int, 2> base;

void prepare(int n){
	base[0] = 67; base[1] = 367;
	fo(i, 0, 1){
		fbase[i].assign(n + 5, 1);
		fo(j, 1, n) fbase[i][j] = fbase[i][j - 1] * base[i] % mod;
	}
}

struct Hash{
	array<vector<int>, 2> h;
	Hash(const string &str){
		int n = str.size();
		fo(i, 0, 1){
			h[i].assign(n + 5, 0);
			fo(j, 1, n) h[i][j] = (h[i][j - 1] * base[i] + str[j - 1]) % mod;
		}
	}
	pair<int, int> get(int l, int r){
		int x = (h[0][r] - h[0][l - 1] * fbase[0][r - l + 1] % mod + mod) % mod;
		int y = (h[1][r] - h[1][l - 1] * fbase[1][r - l + 1] % mod + mod) % mod;
		return {x, y};
	}
};

int n;
string s;

void solve(){
	prepare(5e5);
	cin >> n >> s;
	string t = s;
	for(char &c : t) c = '0' + '1' - c;
	reverse(all(t));
	Hash hs(s), ht(t);
	s = " " + s;
	t = " " + t;
	int res = 0;
	fo(i, 1, n - 1){
		int l = -1, r = n + 1;
		while(r - l > 1){
			int mid = l + r >> 1;
			if(1 <= i - mid and i + 1 + mid <= n and hs.get(i + 1, i + 1 + mid) == ht.get(n + 1 - i, n + 1 - (i - mid))) l = mid;
			else r = mid;
		}
		res += l + 1;
	}
	cout << res;
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	#define file "LonggVuz"
	if(fopen(file".inp", "r")){
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	}
	
	int o = 1; ///cin >> o;
	while(o --> 0) solve();
}