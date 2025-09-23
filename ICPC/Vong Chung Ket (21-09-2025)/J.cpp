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
#define out(x) return void(cout << (x))
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define float double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 2e5 + 7;

int n, a[mxn], f[mxn], t[20], x[mxn];

int tcs(int n){
    int s = 0;
    while(n){
        s += n % 10;
        n /= 10;
    }
    return s;
}

void LonggVuz(){
    t[0] = 1;
    fo(i, 1, 15) t[i] = t[i - 1] * 10;
    cin >> n;
    int tot = 0;
    fo(i, 1, n){
        cin >> a[i];
        f[i] = tcs(a[i]);
        tot += f[i];
    }
    int res = 0;
    fo(i, 1, n) res += f[i] * n + tot;
    debug(res);
    int sub = 0;
    fo(k, 0, 14){
        fo(i, 1, n){
            x[i] = a[i] % t[k + 1];
        }
        sort(x+1, x+n+1);
        int cnt = 0;
        fo(i, 1, n){
            int j = lower_bound(x+1, x+n+1, t[k + 1] - x[i]) - x;
            if(j <= n) cnt += n - j + 1;
        }
        sub += cnt;
        debug(k, cnt);
    }
    cout << res - sub * 9;
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
