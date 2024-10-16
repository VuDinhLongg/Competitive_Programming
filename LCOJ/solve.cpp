// https://luyencode.net/problem/solve
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

int tcs(ll n){
	int res = 0;
	while(n){
		res += n%10;
		n /= 10;
	}return res;
}

int main(){
	LonggVu();
	
	ll n; cin >> n;
	bool ok = 0;
	for(int i=1; i<=165; i++){
		ll d = 1ll*i*i + 4*n;
		ll can = sqrt(d);
		if(can * can != d) continue;
		ll x1 = (-i + can) / 2;
		ll x2 = (-i - can) / 2;
		if(x1 > 0){
			if(tcs(x1) == i){
				cout << x1;
				ok = 1; break;
			}
		}
		if(x2 > 0){
			if(tcs(x2) == i){
				cout << x2;
				ok = 1; break;
			}
		}
	}if(!ok) cout << -1;
}
