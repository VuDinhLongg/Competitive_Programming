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
	int x[100][100];
	matrix(){
		memset(x, 0, sizeof x);
	}
};

const int mod = 1e9 + 7;

int m, k;
int heso[] = {1, 3, 3};

matrix Mul(matrix &a, matrix &b){
	matrix c;
	rep(i, k) rep(j, k) rep(p, k){
		c.x[i][j] += a.x[i][p] * b.x[p][j];
		c.x[i][j] %= mod;
	}
	return c;
}

matrix Pow(matrix &a, int n){
	matrix r;
	rep(i, k) r.x[i][i] = 1;
	while(n){
		if(n & 1) r = Mul(r, a);
		a = Mul(a, a);
		n /= 2;
	}
	return r;
}

void print(matrix &a){
	rep(i, k){
		rep(j, k) cout << a.x[i][j] << ' ';
		el;
	}
}

inline void LonggVuz(){
    cin >> m >> k;
    matrix a;
    a.x[0][0] = 1;
    matrix t;
    rep(i, k){
    	fo(j, i, i + 2){
    		int idx = j % k;
    		t.x[i][idx] = heso[j - i];
    	}
    }
    t = Pow(t, m);
    a = Mul(a, t);
    cout << (a.x[0][0] - 1 + mod) % mod;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
