// https://luyencode.net/problem/thpttd_24
// LonggVu.
#include<bits/stdc++.h>
using namespace std;
// it's AC time! <3
#define LonggVu() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define pb push_back
#define is insert
using ll = long long int;
using ld = long double;
using str = string;



int main(){
	LonggVu();

	ifstream cin;
	ofstream cout;
	cin.open("speed.inp");
	cout.open("speed.out");

	int l, n, m; cin >> l >> n >> m;
	pair<int, int> a[n+5], b[m+5];
	for(int i=1; i<=n; i++){
		cin >> a[i].fi >> a[i].se;
	}
	for(int i=1; i<=m; i++){
		cin >> b[i].fi >> b[i].se;
	}int res = 0, x = 1, y = 1;
	while(x <= n && y <= m){
		res = max(res, b[y].se - a[x].se);
		if(a[x].fi > b[y].fi){
			a[x].fi -= b[y].fi;
			++y;
		}else if(a[x].fi < b[y].fi){
			b[y].fi -= a[x].fi;
			++x;
		}else{
			++x; ++y;
		}
	}cout << res;
}
