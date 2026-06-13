/*
    vudinhlong 9:42:51 sa, 18/12/2024
    => Old style, update later... :D
*/

// LonggVuz
#include<bits/stdc++.h>
using namespace std;
// ☞ Think twice, code once ☜
void End(){
    cerr << "=> Great Job! Execution Time: ";
    cerr << (0.001 * clock()) << "s\n";
}
#define Sonic() cin.tie(0) -> sync_with_stdio(0)
#define out(x) return cout << x, void()
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define pb push_back
#define is insert
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 2e6 + 7;

int n, k;
bool nt[mxn];
vector<int> v;

void pre(){
	int c = sqrtl(1e6);
	for(int i=2; i<=c; i++)
		if(!nt[i])
			for(int j=i*i; j<=1e6; j+=i) nt[j] = 1;

	v.pb(2);
	for(int i=3; i<=1e6; i+=2) if(!nt[i]) v.pb(i);
}

int mu(int a, int b){
	int res = 1;
	while(b){
		if(b % 2) res *= a;
		b /= 2;
		a *= a;
	}return res;
}

int cal(int t1, int t2, int t3){
	int res = 0;
	for(int i=0; i+2<len(v); i++){
		int x = mu(v[i], t1);
		int y = mu(v[i + 1], t2);
		int z = mu(v[i + 2], t3);
		if(x > n / y / z) break;
		res = x * y * z;
	}return res;
}

void LonggVuz(){
	pre();
	cin >> n >> k;
	// (t1 + 1) * (t2 + 1) * (t3 + 1) = k
	int res = -1;
	for(int i=2; i<=k; i++){
		for(int j=2; j<=k and i * j * 2 <= k; j++){
			if(k % (i * j) == 0){
				int t = k / (i * j);
				res = max(res, cal(i - 1, j - 1, t - 1));
			}
		}
	}
	cout << res;
}

signed main(){
	Sonic();
	
	signed icpc = 1;
	//cin >> icpc;
	for(signed i=1; i<=icpc; i++){
		LonggVuz();
	}
	
	End();
}
