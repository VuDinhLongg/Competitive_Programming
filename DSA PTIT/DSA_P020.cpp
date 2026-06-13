// LonggVuz
#include<bits/stdc++.h>
using namespace std;
#define el cout << '\n'
#define inc(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define dec(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int32_t i=a; i<=b; i++)
#define fd(i, a, b) for(int32_t i=a; i>=b; i--)
#define out(x) return void(cout << (x));
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

struct mint{
    int x; mint(int v = 0){ x = v; }
    mint &operator = (int v){ x = v; return *this; }
    // Cal Ops
    mint &operator += (const mint &o){ x += o.x; if(x >= mod) x -= mod; return *this; }
    mint &operator -= (const mint &o){ x -= o.x; if(x < 0) x += mod; return *this; }
    mint &operator *= (const mint &o){ x = ((__int128_t)x * o.x) % mod; return *this; }
    mint &operator /= (const mint &o){ return (*this) *= pow(o, mod - 2); }
    mint operator + (const mint &o) const { return mint(*this) += o; }
    mint operator - (const mint &o) const { return mint(*this) -= o; }
    mint operator * (const mint &o) const { return mint(*this) *= o; }
    mint operator / (const mint &o) const { return mint(*this) /= o; }
    // Cmp Ops
    bool operator == (const mint &o) const { return x == o.x; }
    bool operator != (const mint &o) const { return x != o.x; }
    bool operator > (const mint &o) const { return x > o.x; }
    bool operator < (const mint &o) const { return x < o.x; }
    // Friend Functions
    friend ostream &operator << (ostream &out, const mint &o){ return out << o.x; }
    friend mint operator + (int v, const mint &o){ return mint(v) + o; }
    friend mint operator - (int v, const mint &o){ return mint(v) - o; }
    friend mint operator * (int v, const mint &o){ return mint(v) * o; }
    friend mint operator / (int v, const mint &o){ return mint(v) / o; }
    friend mint pow(mint a, int b){
        mint r = 1;
        while(b){ if(b & 1) r *= a; a *= a; b >>= 1; }
        return r;
    }
};

struct mtr{
    int n;
    vec<vec<mint>> v;
    mtr(int _n){
        n = _n; v.resize(n + 1, vec<mint>(n + 1));
        fo(i, 1, n) v[i][i] = 1;
    }
    mtr operator * (const mtr &o){
        mtr r(n);
        fo(i, 1, n) r.v[i][i] = 0;
        fo(i, 1, n) fo(j, 1, n) fo(k, 1, n){
            r.v[i][j] += v[i][k] * o.v[k][j];
        }
        return r;
    }
};

void LonggVuz(){
    int n, k; cin >> n >> k;
    mtr a(n);
    fo(i, 1, n) fo(j, 1, n){
        int x; cin >> x;
        a.v[i][j] = x;
    }
    mtr r(n);
    while(k){
        if(k & 1) r = r * a;
        a = a * a; k /= 2;
    }
    mint res = 0;
    fo(i, 1, n) res += r.v[1][i];
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
