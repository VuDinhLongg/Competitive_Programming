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
const int mxn = 1e5 + 7;

int n, a[mxn], b[mxn], c[mxn], d[mxn];

void LonggVuz(){
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    fo(i, 1, n) cin >> b[i];
    if(a[1] != b[1] or a[n] != b[n]) out("No");
    fo(i, 1, n - 1) c[i] = abs(a[i] - a[i + 1]);
    fo(i, 1, n - 1) d[i] = abs(b[i] - b[i + 1]);
    sort(c+1, c+n+1);
    sort(d+1, d+n+1);
    fo(i, 1, n - 1) if(c[i] != d[i]) out("No");
    cout << "Yes";
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
