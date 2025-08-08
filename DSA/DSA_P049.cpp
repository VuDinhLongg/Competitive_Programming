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

int n, dp[20][2][8][20];
vec<int> a;

int cal(int pos, int ok, int du, int cur){
    if(pos < 0){
        if(du == 0) return cur;
        return 0;
    }
    int &res = dp[pos][ok][du][cur];
    if(res != -1 and ok) return res;
    res = 0;
    int lim = ok ? 9 : a[pos];
    fo(c, 0, lim){
        int nok = ok or c < a[pos];
        int ndu = (du * 10 + c) % 8;
        int ncur = cur + (c == 6 or c == 8);
        res += cal(pos - 1, nok, ndu, ncur);
    }
    return res;
}

void LonggVuz(){
    cin >> n;
    a.clear();
    while(n){
        a.pub(n % 10);
        n /= 10;
    }
    int res = cal(len(a) - 1, 0, 0, 0);
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    memset(dp, -1, sizeof dp);
    signed orz = 1; cin >> orz;
    while(orz--){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
