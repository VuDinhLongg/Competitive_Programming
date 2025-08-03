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
#define int uint64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 8;
const int mxn = 1e6 + 9;

string res;
int c[66][66];

void run(int a, int b, int k){
    if(a == 0 and b == 0) return;
    if(a and !b){
        res.pb('a'); --a;
        run(a, b, k); return;
    }
    if(b and !a){
        res.pb('b'); --b;
        run(a, b, k); return;
    }
    int n = c[a + b - 1][a - 1];
    if(k > n){
        k -= n;
        res.pb('b');
        --b;
        run(a, b, k);
    }else{
        res.pb('a');
        --a;
        run(a, b, k);
    }
}

void LonggVuz(){
    fo(i, 0, 60) fo(j, 0, i){
        if(j == 0 or j == i) c[i][j] = 1;
        else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    int a, b, k; cin >> a >> b >> k;
    run(a, b, k);
    cout << res;
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
