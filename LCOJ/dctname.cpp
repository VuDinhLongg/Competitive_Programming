// https://luyencode.net/problem/dctname
// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Legendary Grandmaster
void End(){
    cerr << "=> Thời gian code chạy: ";
    cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define Sonic() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define ms(a, x) memset(a, x, sizeof(a))
#define bit(n, x) (n >> x & 1)
#define pb push_back
#define is insert
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;



void LonggVuz(){
	string a, b; cin >> a >> b;
	string res = "";
	int x = 0, y = 0;
	for(char c='z'; c>='a'; c--){
		int cnt1 = 0, cnt2 = 0;
		for(int i=x; i<len(a); i++){
			if(a[i] == c) ++cnt1;
		}
		for(int i=y; i<len(b); i++){
			if(b[i] == c) ++cnt2;
		}
		int cnt = min(cnt1, cnt2);
		if(cnt > 0){
			res += string(cnt, c);
		}
		cnt1 = cnt2 = cnt;
		while(x < len(a) && cnt1 > 0){
			if(a[x] == c) --cnt1;
			++x;
		}
		while(y < len(b) && cnt2 > 0){
			if(b[y] == c) --cnt2;
			++y;
		}
	}cout << res;
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
