// https://luyencode.net/problem/sweshr
// LonggVu.
#include<bits/stdc++.h>
using namespace std;
// Noob C++
void End(){
	cerr << "=> Thời gian code chạy: ";
	cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define LonggVu() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define ms(a, x) memset(a, x, sizeof(a))
#define tc() int TC; cin >> TC; while(TC--)
#define el '\n'
#define fi first
#define se second
#define pb push_back
using ll = long long;
using ld = long double;
using str = string;

void solve(ll n, ll m){
	ll res = 0, sum = m * (m + 1) / 2;
	for(ll i=1; i*i <= n; i++){
		if(n%i == 0){
			if(i >= sum){
				res = n / i;
				break;
			}else{
				ll tmp = n / i;
				if(tmp >= sum){
					res = i;
				}else break;
			}
		}
	}cout << res << el;
}

int main(){
	LonggVu();
	
	tc(){
		ll n, m; cin >> n >> m;
		if(m * (m + 1) / 2 > n){
			cout << "-1\n";
		}else solve(n, m);
	}
	
	End();
}
