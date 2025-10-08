// LonggVuz
#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<LonggVuz.h>
#else
#define debug(...)
#endif

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
#define float double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

int n, k, mx;
int dp[1001][2][1 << 10];
string a;

bool check(int mask){
    int x = mask;
    string s;
    while(mask){
        s.pub(mask % 2 + '0');
        mask /= 2;
    }
    while(len(s) < k) s.pub('0');
    string t = s;
    reverse(all(t));
    return s == t;
}

int cal(int pos, int ok, int mask){
    if(pos == n){
        if(ok) return 0;
        return 1;
    }
    int &res = dp[pos][ok][mask];
    if(res != -1) return res;
    res = 0;
    if(a[pos] == 'A'){
        int nmask = ((mask << 1) & mx) | 1;
        int nok = ok;
        if(pos + 1 >= k) nok = nok or check(nmask);
        res += cal(pos + 1, nok, nmask);
        res %= mod;
    }else if(a[pos] == 'B'){
        int nmask = ((mask << 1) & mx) | 0;
        int nok = ok;
        if(pos + 1 >= k) nok = nok or check(nmask);
        res += cal(pos + 1, nok, nmask);
        res %= mod;
    }else{
        {
            int nmask = ((mask << 1) & mx) | 1;
            int nok = ok;
            if(pos + 1 >= k) nok = nok or check(nmask);
            res += cal(pos + 1, nok, nmask);
            res %= mod;
        }
        {
            int nmask = ((mask << 1) & mx) | 0;
            int nok = ok;
            if(pos + 1 >= k) nok = nok or check(nmask);
            res += cal(pos + 1, nok, nmask);
            res %= mod;
        }
    }
    return res;
}

void LonggVuz(){
    cin >> n >> k >> a;
    mx = (1 << k) - 1;
    memset(dp, -1, sizeof dp);
    cout << cal(0, 0, 0);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; if(false) cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
