/*
  https://luyencode.net/problem/cd2b17
*/
// LonggVu.
#include<bits/stdc++.h>
using namespace std;
// Noob C++
void End(){
	cerr << "=> Thời gian code chạy: ";
	cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define LonggVu() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
using ll = long long;
using ld = long double;
using str = string;

str tich(str a, str b){
	if(a == "0" || b == "0"){
		return "0";
	}str res = "";
	int n = a.size() - 1, m = b.size() - 1, nho = 0;
	for(int i=0; i<=m+n || nho; i++){
		for(int j=max(0, i-m); j<=min(i, n); j++){
			nho += (a[n-j] - '0') * (b[m-i+j] - '0');
		}res += nho%10 + '0';
		nho /= 10;
	}reverse(res.begin(), res.end());
	return res;
}

int r[105], s[105], len;
void edit(int n, int x){
	int c = sqrtl(n);
	for(int i=2; i<=c; i++){
		while(n%i==0){
			s[i] += x;
			n /= i;
		}
	}if(n != 1){
		s[n] += x;
	}
}

void nhan(int n){
	len += 10;
	for(int i=0; i<len; i++){
		r[i] *= n;
	}
	for(int i=0; i<len; i++){
		r[i+1] += r[i]/10; 
		r[i] %= 10;
	}while(len > 0 && r[len-1] == 0) --len;
}

void solve(int n, int k){
	//edit(2, 1);
	for(int i=n-k+1; i<=n; i++){
		edit(i, 1);
	}
	for(int i=1; i<=k; i++){
		edit(i, -1);
	}r[0] = len = 1;
	for(int i=1; i<=100; i++){
		while(s[i]--){
			nhan(i);
		}
	}str res = "";
	for(int i=len-1; i>=0; i--){
		res += to_string(r[i]);
	}cout << tich(res, res);
}

int main(){
	LonggVu();
	
	int n, k; cin >> k >> n;
	solve(n, k);
	
	End();
}
