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

int cnt;

int cal(int n){
    int res = 1;
    for(int i=2; i*i<=n; i++){
        if(n % i == 0){
            res = i;
            cnt = 0;
            while(n % i == 0){
                ++cnt;
                n /= i;
            }
        }
    }
    if(n > 1) res = n, cnt = 1;
    return res;
}

void LonggVuz(){
    int n, k; cin >> n >> k;
    int u = cal(k);
    int res = 0;
    while(n >= u){
        res += n / u;
        n /= u;
    }
    cout << res / cnt;
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
