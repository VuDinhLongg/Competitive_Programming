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

str c[105];
str tich(str a, str b){
	if(a == "0" || b == "0"){
		return "0";
	}str res = "";
	int n = len(a) - 1, m = len(b) - 1, nho = 0;
	for(int i=0; i<=m+n || nho; i++){
		for(int j=max((int)0, i-m); j<=min(i, n); j++){
			nho += (a[n-j] - '0') * (b[m-i+j] - '0');
		}res += nho%10 + '0';
		nho /= 10;
	}reverse(all(res));
	return res;
}

str tong(str a, str b){
	if(a < b) swap(a, b);
	reverse(all(a)); reverse(all(b));
	int len = max(len(a), len(b));
	while(len(a) < len) a.pb('0');
	while(len(b) < len) b.pb('0');
	str res = "";
	int nho = 0;
	for(int i=0; i<len; i++){
		int tmp = (a[i] - '0') + (b[i] - '0') + nho;
		res.pb(tmp%10 + '0');
		nho = tmp/10;
	}if(nho) res.pb(nho + '0');
	reverse(all(res));
	return res;
}

void hehe(){
	c[0] = "1";
	for(int i=1; i<=100; i++){
		for(int j=0; j<i; j++){
			c[i] = tong(c[i], tich(c[i - j - 1], c[j]));
		}
	}
}

signed main(){
	LonggVuz();
	
	hehe();
	tc(){
		int n; cin >> n;
		cout << c[n] << el;
	}
	
	End();
}