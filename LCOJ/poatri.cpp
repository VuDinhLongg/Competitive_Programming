/*
  https://luyencode.net/problem/poatri
*/
// LonggVu.
#include<bits/stdc++.h>
using namespace std;
// Noob C++
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

ll gcd(ll a, ll b){
	if(!b) return a;
	return gcd(b, a%b);
}

int main(){
	LonggVu();

	int t; cin >> t;
	while(t--){
		ll a, b; cin >> a >> b;
		ll u = gcd(a, b);
		ll x = a + b + u;
		ll s = abs(a * b);
		ll y = (s - x + 2) / 2;
		cout << x << ' ' << y << el;
	}
}
