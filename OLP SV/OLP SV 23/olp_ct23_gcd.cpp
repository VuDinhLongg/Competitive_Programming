/*======================
   Author : @LonggVuz
======================*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define orz(...) 2005
#endif

#define el cout << '\n'
#define all(x) begin(x), end(x)
#define len(x) (x).size()
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 1'000'007

struct matrix{
	int x[2][2];
	matrix(){
		memset(x, 0, sizeof x);
	}
};

int a, b, m;

int nhan(int a, int b){
	if(b == 0) return 0;
	int res = nhan(a, b / 2);
	res += res;
	if(b & 1) res += a;
	return res % m;
}

matrix Mul(matrix &a, matrix &b){
	matrix r;
	rep(i, 2) rep(j, 2) rep(k, 2){
		r.x[i][j] += nhan(a.x[i][k], b.x[k][j]);
		r.x[i][j] %= m;
	}
	return r;
}

matrix Pow(matrix &a, int n){
	matrix r;
	r.x[0][0] = r.x[1][1] = 1;
	while(n){
		if(n & 1) r = Mul(r, a);
		a = Mul(a, a);
		n /= 2;
	}
	return r;
}

int fibo(int n){
	if(n <= 1) return n;
	--n;
	matrix a;
	a.x[0][0] = 1;
	matrix t;
	t.x[0][0] = t.x[0][1] = t.x[1][0] = 1;
	t = Pow(t, n);
	a = Mul(a, t);
	return a.x[0][0];
}

inline void LonggVuz(){
    cin >> a >> b >> m;
    cout << fibo(gcd(a, b));
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
