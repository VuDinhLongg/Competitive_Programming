#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define orz(...) 2005
#endif

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x),end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 1'000'007

string tong(string a, string b){
    reverse(all(a));
    reverse(all(b));
    int len = max(a.size(), b.size());
    while(a.size() < len) a.push_back('0');
    while(b.size() < len) b.push_back('0');
    string res = "";
    int nho = 0;
    fo(i, 0, len - 1){
        int tmp = (a[i] - '0') + (b[i] - '0') + nho;
        res.push_back(tmp % 10 + '0');
        nho = tmp / 10;
    }
    if(nho) res.push_back(nho + '0');
    reverse(all(res));
    return res;
}

string smin(const string &a, const string &b){
	if(len(a) > len(b)) return b;
	if(len(a) < len(b)) return a;
	return min(a, b);
}

inline void LonggVuz(){
	string s; cin >> s;
	string res = s;
	int n = len(s);
	s = " " + s;
	vector<int> idx_i, idx_j;
	fo(i, n / 3 + 1, n - 2) if(i > 1 and s[i] != '0'){
		idx_i.push_back(i - 1);
		if(len(idx_i) == 5) break;
	}
	fd(i, n / 3 + 1, 2) if(s[i] != '0'){
		idx_i.push_back(i - 1);
		if(len(idx_i) == 9) break;
	}
	fo(i, n / 3 * 2 + 1, n) if(i > 1 and (s[i] != '0' or i == n)){
		idx_j.push_back(i - 1);
		if(len(idx_j) == 5) break;
	}
	fd(i, n / 3 * 2 + 1, 3) if(s[i] != '0' or i == n){
		idx_j.push_back(i - 1);
		if(len(idx_j) == 9) break;
	}
	sort(all(idx_i));
	sort(all(idx_j));
	dbg(idx_i, idx_j);
	auto check = [&](int l, int r){
		int len = r - l + 1;
		if(len == 1) return true;
		if(s[l] == '0') return false;
		return true;
	};
	for(int &i : idx_i) for(int &j : idx_j) if(check(1, i) and check(i + 1, j) and check(j + 1, n)){
		string num1 = s.substr(1, i);
		string num2 = s.substr(i + 1, j - i);
		string num3 = s.substr(j + 1, n - j);
		string t = tong(tong(num1, num2), num3);
		res = smin(res, t);
	}
	fo(i, 2, n - 1) if(s[i] == '0' and check(1, i - 1) and check(i + 1, n)){
		if(max<int>({i - 1, 1, n - i}) > len(res)) continue;
		string t = tong(s.substr(1, i - 1), s.substr(i + 1, n - i));
		res = smin(res, t);
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "LonggVuz"
	if(fopen(name".inp", "r")){
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
