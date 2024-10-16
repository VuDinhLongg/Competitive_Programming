// https://luyencode.net/problem/mulprime
// LonggVu.
#include<bits/stdc++.h>
using namespace std;
// I Love Coding! <3
#define LonggVu() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define use(name) ifstream in(name".inp"); ofstream out(name".out");
#define fix(x) fixed << setprecision(x)
#define skip cin.ignore()
#define M 1000000007
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define is insert
using ll = long long int;
using ld = long double;
using str = string;

ll n, a[15], l, r, ok, so;
vector<int> v;

void ql(int i){
	for(int j=i; j<=n; j++){
		ll tmp = so * a[j];
		if(!(tmp > r)){
			if(tmp >= l){
				ok = 1;
				v.pb(tmp);
			}
			so *= a[j];
			ql(j);
			so /= a[j];
		}
	}
}

int main(){
	LonggVu();

	while(1){
		cin >> n;
		if(n == 0) break;
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}cin >> l >> r;
		if(l == 1) v.pb(1);
		so = 1; ok = 0;
		ql(1);
		if(ok){
			sort(v.begin(), v.end());
			for(auto x : v){
				cout << x;
				if(x != v[v.size() - 1]) cout << ',';
			}cout << endl;
			v.clear();
		}else cout << "none\n";
	}
}
