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

const int mod = 1e9 + 7;
const int mxn = 1e6 + 7;

double dp[101][101][101];

double cal(int a, int b, int c){
    if(max({a, b, c}) == 100) return 1.0;
    double &res = dp[a][b][c];
    if(res) return res;
    int s = a + b + c;
    res += (cal(a + 1, b, c) + 1) * a / s;
    res += (cal(a, b + 1, c) + 1) * b / s;
    res += (cal(a, b, c + 1) + 1) * c / s;
    return res;
}

void LonggVuz(){
    int a, b, c; cin >> a >> b >> c;
    cout << fixed << setprecision(6) << cal(a, b, c) - 1;
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
