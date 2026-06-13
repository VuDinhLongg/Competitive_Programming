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

const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

#define i128 __int128_t
int n, mod;

struct mint{
    int x; mint(int v = 0){ x = v; }
    mint &operator = (int v){ x = v; return *this; }
    // Cal Ops
    mint &operator += (const mint &o){ x += o.x; if(x >= mod) x -= mod; return *this; }
    mint &operator -= (const mint &o){ x -= o.x; if(x < 0) x += mod; return *this; }
    mint &operator *= (const mint &o){ x = ((i128)x * o.x) % mod; return *this; }
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
    mint f[2][2];
    mtr(){ memset(f, 0, sizeof f); }
    mtr operator * (const mtr &o){
        mtr m;
        fo(i, 0, 1) fo(j, 0, 1) fo(k, 0, 1){
            m.f[i][j] += f[i][k] * o.f[k][j];
        }
        return m;
    }
};

void LonggVuz(){
    cin >> n >> mod;
    if(n <= 1) out(1 % mod);
    mtr r;
    r.f[0][0] = r.f[1][1] = 1;
    mtr m;
    m.f[0][0] = m.f[0][1] = m.f[1][0] = 1;
    while(n){
        if(n & 1) r = r * m;
        m = m * m; n >>= 1;
    }
    cout << r.f[0][0];
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
