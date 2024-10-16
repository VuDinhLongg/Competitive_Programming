/*
  //luyencode.net/problem/quaytron
*/
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
#define sz(x) (int)x.size()
#define ms(a, x) memset(a, x, sizeof(a))
#define el '\n'
#define fi first
#define se second
#define pb push_back
using ll = long long;
using ld = long double;
using str = string;

ld dis(ld s1, ld s2, ld f1, ld f2){
	return sqrtl((s1-f1)*(s1-f1) + (s2-f2)*(s2-f2));
}

int main(){
	LonggVu();
	
	ld r, s1, s2, f1, f2;
	cin >> r >> s1 >> s2 >> f1 >> f2;
	ld res = dis(s1, s2, f1, f2);
	res /= (2 * r);
	if(res != (ll)res) res = (ll)res + 1;
	cout << res;
	
	AC();
}
