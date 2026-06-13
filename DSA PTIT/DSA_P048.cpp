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

#define bit(n, i) (n >> (i) & 1)
int n, k, msb, dp[33][2][33][2];
// dp[pos][ok][cur][dg]

int cal(int pos, bool ok, int cur, bool dg){
    if(pos < 0){
        return dg and cur == k;
    }
    int &res = dp[pos][ok][cur][dg];
    if(res != -1) return res;
    res = 0;
    int b = bit(n, pos);
    int lim = ok ? 1 : b;
    fo(c, 0, lim){
        bool nok = ok or c < b;
        int ncur = cur + (dg and c == 0);
        bool ndg = dg or c == 1;
        res += cal(pos - 1, nok, ncur, ndg);
    }
    return res;
}

void LonggVuz(){
    cin >> n >> k;
    if(n == 0){
        cout << (k == 1 ? "1\n" : "0\n");
        return;
    }
    msb = 31;
    while(bit(n, msb) == 0) --msb;
    memset(dp, -1, sizeof dp);
    int res = cal(msb, 0, 0, 0);
    if(k == 1) ++res;
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; cin >> orz;
    while(orz--){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
