// LonggVuz
#include<bits/stdc++.h>
using namespace std;
#define el cout << '\n'
#define inc(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define dec(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int64_t i=a; i<=b; i++)
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
    // LonggVuz's Snippet
    int x; mint(int v = 0){ x = (v % mod + mod) % mod; }
    mint &operator = (int v){ x = v; return *this; }
    // Cal Ops
    mint &operator += (const mint &o){ x += o.x; if(x >= mod) x -= mod; return *this; }
    mint &operator -= (const mint &o){ x -= o.x; if(x < 0) x += mod; return *this; }
    mint &operator *= (const mint &o){ x = (x * o.x) % mod; return *this; }
    mint &operator /= (const mint &o){ return (*this) *= Pow(o, mod - 2); }
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
    friend mint Pow(mint a, int b){
        mint r = 1;
        while(b){ if(b & 1) r *= a; a *= a; b >>= 1; }
        return r;
    }
};

int mu(int a, int b, int m = mod){
    int res = 1;
    while(b){
        a %= m;
        if(b & 1) res = (res * a) % m;
        a *= a; b /= 2;
    }
    return res;
}

int n, m;
mint f[mxn], ivf[mxn], pn[mxn], pm[mxn];

void pre(){
    int mx = 1e6;
    f[0] = 1;
    fo(i, 1, mx) f[i] = f[i - 1] * i;
    ivf[mx] = Pow(f[mx], mod - 2);
    fd(i, mx, 1) ivf[i - 1] = ivf[i] * i;
    pn[0] = 1;
    fo(i, 1, mx) pn[i] = pn[i - 1] * n;
    pm[0] = 1;
    fo(i, 1, mx) pm[i] = pm[i - 1] * m;
}

mint C(int n, int k){
    if(n < k) return 0;
    return f[n] * ivf[k] * ivf[n - k];
}

void LonggVuz(){
    cin >> n >> m;
    pre();
    mint res = 0;
    fo(i, 1, n - 1){
        mint path = C(m - 1, i - 1) * C(n - 2, i - 1) * f[i - 1];
        int rem = n - (i + 1);
        if(rem == 0){
            res += path;
        }else{
            mint cay = pn[rem - 1] * (i + 1) * pm[rem];
            res += path * cay;
        }
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; //cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
