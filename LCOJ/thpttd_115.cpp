// https://luyencode.net/problem/thpttd_115
// LonggVu.
#include<bits/stdc++.h>
using namespace std;
// Noob C++
#define LonggVu() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define fix(x) fixed << setprecision(x)
#define skip scanf("\n");
#define mod 1000000007
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define is insert
using ll = long long int;
using ld = long double;
using str = string;

int search(ld a[], int l, int r, ld x){
	int res = -1;
	while(l <= r){
		int m = (l + r)/2;
		if(a[m] <= x){
			res = m;
			l = m + 1;
		}else r = m - 1;
	}return res;
}

void solve(ld a[], int n){
	sort(a+1, a+n+1);
	ll res = 0;
	for(int i=1; i<=n; i++){
		int pos = search(a, i+1, n, a[i] * 10 / 9);
		if(pos != -1){
			//cout << i << ' ' << pos << el;
			res += pos - i;
		}
	}cout << res;
}

int main(){
	LonggVu();
	use("cfile");

	int n; cin >> n;
	ld a[n+5];
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}solve(a, n);
}
