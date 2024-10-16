// https://luyencode.net/problem/matrixmul
// LonggVu.
#include<bits/stdc++.h>
using namespace std;
// it's AC time! <3
#define LonggVu() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define pb push_back
using ll = long long int;
using ld = long double;
using str = string;

void solve(pair<ll, ll> a[], int n){
	ll r[n+5][n+5] = {0};
	//for(int i=1; i<=n; i++) r[i][i] = 0;
	for(int l=2; l<=n; l++){
		for(int i=1; i<=n-l+1; i++){
			int j = i + l - 1;
			r[i][j] = 1e17;
			for(int k=i; k<=j; k++){
				r[i][j] = min(r[i][j], r[i][k] + r[k+1][j] + a[i].fi * a[k].se * a[j].se);
			}
		}
	}cout << r[1][n];
}

int main(){
	LonggVu();

	int n; cin >> n;
	ll t[n+5];
	for(int i=1; i<=n+1; i++){
		cin >> t[i];
	}
	pair<ll, ll> a[n+5];
	for(int i=1; i<=n; i++){
		a[i].fi = t[i];
		a[i].se = t[i+1];
	}solve(a, n);
}
