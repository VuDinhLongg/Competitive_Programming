// https://luyencode.net/problem/thpttd_100
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
#define mod 1000000007
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define is insert
using ll = long long int;
using ld = long double;
using str = string;

vector<pair<int, int>> v;
void solve(int a[], int n){
	for(int len=1; len<=n; len++){
		for(int i=1; i<=n-len+1; i++){
			bool ok = 1;
			for(int j=i; j<=i+len-1; j++){
				if(a[j] > len){
					ok = 0; break;
				}
			}if(ok){
				v.pb({i, i+len-1});
			}
		}
	}cout << v.size() << el;
	for(auto x : v){
		cout << x.fi << ' ' << x.se << ' ' << x.se - x.fi + 1 << el;
	}
}

int main(){
	LonggVu();
	
	use("bai3")
	int n; cin >> n;
	int a[n+5];
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}solve(a, n);
	
	AC();
}
