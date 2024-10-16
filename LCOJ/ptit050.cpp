// https://luyencode.net/problem/ptit050
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

void solve(ll a, ll b, ll c, ll d){
	ll u = gcd(c, d);
	c /= u; d /= u;
	if(a * d == b * c){
		cout << "0\n";
		return;
	}
	if(a < b && c == d){
		cout << "-1\n";
		return;
	}
	ll mot = a / c;
	if(a%c != 0) ++mot;
	ll hai = b / d;
	if(b%d != 0) ++hai;
	ll x = max(mot, hai);
	ll C = c, D = d;
	c *= x; d *= x;
	while(a + d - b < c){
		c += C; d += D;
	}cout << d - b << el;
}

int main(){
	LonggVu();
	
	int t; cin >> t;
	while(t--){
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		solve(a, b, c, d);
	}
}
