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
const int mxn = 1e5 + 7;

int n, k, a[mxn];

int rmq[20][mxn];

inline int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

void build(int a[], int n){
    fo(i, 1, n) rmq[0][i] = a[i];
    for(int k=1; 1<<k <= n; k++){
        for(int i=1; i+(1<<k)-1 <= n; i++){
            rmq[k][i] = gcd(rmq[k - 1][i], rmq[k - 1][i + (1<<k-1)]);
        }
    }
}

int get(int l, int r){
    int k = 20, x = r - l + 1;
    while(!(x >> k & 1)) --k;
    return gcd(rmq[k][l], rmq[k][r - (1<<k) + 1]);
}

void LonggVuz(){
    cin >> n >> k;
    fo(i, 1, n) cin >> a[i];
    build(a, n);
    int res = oo;
    fo(i, 1, n){
        int l = i - 1, r = n + 1;
        while(r - l > 1){
            int mid = l + r >> 1;
            if(get(i, mid) <= k) r = mid;
            else l = mid;
        }
        if(r <= n and get(i, r) == k) res = min(res, r - i + 1);
    }
    cout << (res < oo ? res : -1);
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
