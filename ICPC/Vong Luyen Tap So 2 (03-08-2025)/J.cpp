// LonggVuz
#include<bits/stdc++.h>
using namespace std;
#define el cout << '\n'
#define inc(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define dec(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int64_t i=a; i<=b; i++)
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

bool cp(int n){
    if(n == 0) return 0;
    int c = sqrtl(n);
    return c * c == n;
}

void LonggVuz(){
    int a; cin >> a;
    int aa = a * a * 2;
    int can = sqrtl(aa);
    fo(b, 1, min(can, (int)1e5)){
        int c = aa - b * b;
        if(a != b and cp(c)){
            c = sqrtl(c);
            if(a != c and b != c and c <= 1e5){
                // cout << a << ' ' << b << ' ' << c, el;
                out("YES");
            }
        }
    }
    cout << "NO";
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; //cin >> orz;
    while(orz--){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
