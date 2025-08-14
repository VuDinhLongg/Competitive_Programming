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

int n, j, k, a[mxn], d[mxn];

void LonggVuz(){
    cin >> n >> j >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        d[i] = d[i - 1] + a[i];
    }
    int i = -1, l = 1, r = j;
    while(l <= r){
        int mid = (l + r) / 2;
        if(d[j] - d[mid - 1] <= k){
            i = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    cout << i;
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
