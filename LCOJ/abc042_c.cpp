// https://luyencode.net/problem/abc042_c
// LonggVu.
#include<bits/stdc++.h>
using namespace std;
// Noob C++
void AC(){
	cerr << "=> Thời gian code chạy: ";
	cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define LonggVu() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define ms(a, x) memset(a, x, sizeof(a))
#define el '\n'
#define fi first
#define se second
#define pb push_back
using ll = long long;
using ld = long double;
using str = string;

int n, s, d;
bool mark[12];
bool check(int n){
	while(n){
		int cs = n % 10;
		if(mark[cs]) return 0;
		n /= 10;
	}return 1;
}

int main(){
	LonggVu();
	
	cin >> s >> n;
	for(int i=0; i<n; i++){
		cin >> d;
		mark[d] = 1;
	}int res = s;
	while(!check(res)){
		++res;
	}cout << res;
	
	AC();
}
