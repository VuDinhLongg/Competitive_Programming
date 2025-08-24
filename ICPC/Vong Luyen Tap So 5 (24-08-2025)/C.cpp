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

int mu(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = (res * a);
        a *= a; b /= 2;
    }
    return res;
}

void LonggVuz(){
    int n, p; cin >> n >> p;
    int res = 1;
    for(int i=2; i*i<=p; i++) if(p % i == 0){
        int cnt = 0;
        while(p % i == 0){
            ++cnt;
            p /= i;
        }
        if(cnt >= n) res *= mu(i, cnt / n);
    }
    if(p > 1 and 1 >= n) res *= p;
    cout << res;
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
