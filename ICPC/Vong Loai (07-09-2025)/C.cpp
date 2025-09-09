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
const int mxn = 2e5 + 7;

#define i128 __int128_t
string value(i128 n){
    string s = "";
    bool neg = 0;
    if(n < 0) neg = 1, n = -n;
    while(n) s.pub(n % 10 + '0'), n /= 10;
    reverse(all(s));
    if(neg) s.insert(begin(s), '-');
    return s;
}

int n, a[mxn];

void LonggVuz(){
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    i128 res = 0, cur = 0;
    fo(i, 1, n){
        res += a[i] * (i - 1) - cur;
        cur += a[i];
    }
    cout << value(res);
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
