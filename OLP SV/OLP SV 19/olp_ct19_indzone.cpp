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
#define fix(x) fixed << setprecision(x)
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 1'000'007

const int mod = 998244353;

struct mint{
    int x; mint(const int &o = 0){ x = o % mod; if(x < 0) x += mod; }
    mint &operator = (const mint &o){ x = o.x; return *this; }
    mint &operator += (const mint &o){ x += o.x; if(x >= mod) x -= mod; return *this; }
    mint &operator -= (const mint &o){ x -= o.x; if(x < 0) x += mod; return *this; }
    mint &operator *= (const mint &o){ x = x * o.x % mod; return *this; }
    mint &operator /= (const mint &o){ return (*this) *= Pow(o, mod - 2); }
    mint operator + (const mint &o) const { return mint(*this) += o; }
    mint operator - (const mint &o) const { return mint(*this) -= o; }
    mint operator * (const mint &o) const { return mint(*this) *= o; }
    mint operator / (const mint &o) const { return mint(*this) /= o; }
    bool operator == (const mint &o) const { return x == o.x; }
    bool operator != (const mint &o) const { return x != o.x; }
    bool operator > (const mint &o) const { return x > o.x; }
    bool operator < (const mint &o) const { return x < o.x; }
    friend ostream &operator << (ostream &out, const mint &o){ return out << o.x; }
    friend mint Pow(mint a, int b){
        mint r = 1;
        while(b){ if(b & 1) r *= a; a *= a; b >>= 1; }
        return r;
    }
};

struct matrix{
    int n; mint x[2][2];
    matrix(bool id = false){ // mtr dvi ?
    	n = 2; memset(x, 0, sizeof x);
        if(id) rep(i, n) x[i][i] = 1;
    }
    matrix operator * (const matrix &o){
        matrix r;
        rep(i, n) rep(j, n) rep(k, n){
            r.x[i][j] += x[i][k] * o.x[k][j];
        }
        return r;
    }
    matrix Pow(int p){
        matrix res(true);
        matrix t = *this;
        while(p){
            if(p & 1) res = res * t;
            t = t * t; p >>= 1;
        }
        return res;
    }
    friend ostream &operator << (ostream &out, const matrix &mtr){
        rep(i, mtr.n){
            rep(j, mtr.n) out << mtr.x[i][j] << ' ';
            out << '\n';
        }
        return out;
    }
};

mint fibo(int n){
    maxi(n, 1);
	if(n <= 2) return n;
	n -= 2;
	matrix r;
	r.x[0][0] = r.x[0][1] = r.x[1][0] = 1;
	r = r.Pow(n);
	matrix a;
	a.x[0][0] = 2;
	a.x[1][0] = 1;
	r = r * a;
	return r.x[0][0];
}

inline void LonggVuz(){
    int n; cin >> n;
    cout << fibo(n) * fibo(n + 1);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}