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
const int mxn = 1e6 + 7;

#define ld long double
ld dp[101][101][101], one = 1.0;

ld cal(int a, int b, int c){
    if(a == 100 or b == 100 or c == 100){
        return 1.0;
    }
    ld &res = dp[a][b][c];
    if(res) return res;
    res += one * a / (a + b + c) * (cal(a + 1, b, c) + 1.0);
    res += one * b / (a + b + c) * (cal(a, b + 1, c) + 1.0);
    res += one * c / (a + b + c) * (cal(a, b, c + 1) + 1.0);
    return res;
}

void LonggVuz(){
    int a, b, c; cin >> a >> b >> c;
    cout << fixed << setprecision(6) << cal(a, b, c) - 1.0;
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
