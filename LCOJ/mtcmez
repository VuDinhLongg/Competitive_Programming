// https://luyencode.net/problem/mtcmez
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
ll m = 1000000007;
ll gt(ll n){
	ll res = 1;
	for(ll i=2; i<=n; i++){
		res *= i;
	}return res;
}
int main(){
	cin.tie(0) -> sync_with_stdio(0);
	ll a, b;
	string s; cin >> a >> s >> b;
	int n = s.size();
	if(n>=2){
		if(s[0]=='!'){
			a = gt(a);
		}else{
			a = sqrt(a);
		}s[0] = s[n-1]; n=1;
		//cout << s << endl;
	}if(n==1){
		if(s[0]=='+') cout << a+b;
		else if(s[0]=='-') cout << a-b;
		else if(s[0]=='*') cout << a*b;
		else if(s[0]=='/') cout << a/b;
		else cout << (ll)pow(a, b);
	}
}
