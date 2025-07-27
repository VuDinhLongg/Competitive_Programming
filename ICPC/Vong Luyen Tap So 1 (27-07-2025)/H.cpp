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
#define pb push_back
#define po pop_back
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 8;
const int mxn = 1e6 + 9;



void LonggVuz(){
    int a, b; cin >> a >> b;
    if(a < b) swap(a, b);
    int res = 0, d = a - b;
    while(1){
        int s = res * (res + 1) / 2;
        int t = s + d;
        if(t % 2 == 0){
            int y = t / 2;
            int x = s - y;
            if(x >= 0 and y >= 0 and a + x == b + y) out(res);
        }
        ++res;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int o = 1; cin >> o;
    while(o){
        LonggVuz();
        if(--o) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
    return (0 ^ 0);
}
