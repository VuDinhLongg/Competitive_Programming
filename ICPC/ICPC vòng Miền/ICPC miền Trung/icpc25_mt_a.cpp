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

const int mod = 1e9 + 7;

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

int n, m, a[22];
mint c[22][22], dp[22][22][22];
// dp[i][j][k] : so cach thuc hien j thao tac khi xet den vi tri i, 
//               co k thao tac ket thuc o vi tri i

void pre(){
    fo(i, 0, 20){
        fo(j, 0, i){
            if(j == 0 or j == i) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

inline void LonggVuz(){
    pre();
    cin >> n >> m;
    fo(i, 1, n) cin >> a[i];
    fo(j, 0, m) dp[1][j][j] = 1;
    fo(i, 2, n){
        fo(j, 0, m){
            fo(k, 0, j){
                fo(x, 0, k){
                    fo(p, 0, j - x) if(a[i] + k > a[i - 1] + p){
                        dp[i][j][k] += dp[i - 1][j - x][p] * c[p][k - x] * c[j][x];
                    }
                }
                // debug(i, j, k, dp[i][j][k]);
            }
        }
    }
    mint res = 0;
    fo(k, 0, m) res += dp[n][m][k];
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}