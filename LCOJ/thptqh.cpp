// https://luyencode.net/problem/thptqh
// LonggVu.
#include<bits/stdc++.h>
using namespace std;
// I Love Coding! <3
#define LonggVu() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define use(name) ifstream in(name".inp"); ofstream out(name".out");
#define fix(x) fixed << setprecision(x)
#define M 1000000007
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define is insert
using ll = long long int;
using ld = long double;
using str = string;

use("TRANSTR");

void solve(str a, int n){
	int res = 0, ok = 1, cnt = 0;
	for(int i=n-1; i>=0; i--){
		if(ok){
			if(a[i] == 'B'){
				++cnt;
			}else{
				if(cnt == 1){
					++res;
				}else if(cnt > 1){
					++res;
					ok = 0;
					++i;
				}cnt = 0;
			}
		}else{
			if(a[i] == 'A'){
				++cnt;
			}else{
				if(cnt == 1){
					++res;
				}else if(cnt > 1){
					++res;
					ok = 1;
					++i;
				}cnt = 0;
			}
		}
	}if(cnt) ++res;
	out << res;
}

int main(){
	LonggVu();

	str a; in >> a;
	solve(a, a.size());
}
