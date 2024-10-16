// https://luyencode.net/problem/thpttd_76
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

int n, m;
ll a[3000005], b[3000005];
unordered_map<ll, ll> mp1, mp2;
ll res;

int main(){
	LonggVu();
	use("thuong");

	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		mp1[a[i]]++;
	}
	for(int i=1; i<=m; i++){
		cin >> b[i];
		mp2[b[i]] = 1;
	}
	for(int i=1; i<=n; i++){
		if(mp2[a[i]] == 0){
			cout << a[i] << ' ';
			res = max(res, a[i] * mp1[a[i]]);
		}
	}cout << el << res;
}
