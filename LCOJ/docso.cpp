/*
  https://luyencode.net/problem/docso
*/
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

str so[] = {"khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin", "muoi"};
str chuc[] = {"", "", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};
str dvi[] = {"", "mot", "hai", "ba", "bon", "lam", "sau", "bay", "tam", "chin"};

void xuli(vector<int> v){
	if(v[0] != 0){
		if(v[1] == 0){
			if(v[0] != 4) cout << so[v[2]] << " tram linh " << so[v[0]] << el; 
			else cout << so[v[2]] << " tram linh tu\n";
		}else if(v[1] == 1){
			cout << so[v[2]] << " tram muoi " << dvi[v[0]] << el;
		}else{
			if(v[0] != 4) cout << so[v[2]] << " tram " << chuc[v[1]] << " muoi " << dvi[v[0]] << el;
			else cout << so[v[2]] << " tram " << chuc[v[1]] << " muoi tu\n";
		}
	}else{
		if(v[1] == 0){
			cout << so[v[2]] << " tram\n";
		}else if(v[1] == 1){
			cout << so[v[2]] << " tram muoi " << dvi[v[0]] << el;
		}else{
			if(v[0] != 4) cout << so[v[2]] << " tram " << chuc[v[1]] << " muoi " << dvi[v[0]] << el;
			else cout << so[v[2]] << " tram " << chuc[v[1]] << " muoi tu\n";
		}
	}
}

void solve(int n){
	if(n <= 10){
		cout << so[n] << el;
	}else if(n == 1000) cout << "mot nghin\n";
	else{
		int x = n;
		vector<int> v;
		while(n){
			v.pb(n%10);
			n /= 10;
		}if(v.size() == 2){
			if(x < 20){
				cout << "muoi " << dvi[v[0]] << el;
			}else{
				if(v[0] != 4) cout << chuc[v[1]] << " muoi " << dvi[v[0]] << el;
				else cout << chuc[v[1]] << " muoi tu\n";
			}
		}else xuli(v);
	}
}

int main(){
	LonggVu();

	//for(int i=1; i<=1000; i++) solve(i);

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		solve(n);
	}
}
