// https://luyencode.net/problem/bitstr
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

const int m = 1000007;

int r[100005];
int fb[100005];

void init(int k){
	fb[1] = 1;
	for(int i=2; i<=k; i++){
		fb[i] = fb[i-1] * 2;
		fb[i] %= m;
	}
	for(int i=k+1; i<=100001; i++){
		for(int j=i-k; j<i; j++){
			fb[i] += fb[j];
			fb[i] %= m;
		}
	}
}

int main(){
	LonggVu();

	int n, k; cin >> n >> k;
	if(n < k){
		cout << 0;
	}else{
		if(k == 1){
			r[1] = 1;
			for(int i=2; i<=n; i++){
				r[i] = r[i-1] * 2 - 1;
				r[i] %= m;
			}cout << r[n];
		}else{
			init(k);
			r[k] = 1;
			for(int i=k+1; i<=n; i++){
				r[i] = r[i-1] * 2 + fb[i-k];
				r[i] %= m;
			}cout << r[n];
		}
	}
}
