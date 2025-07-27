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

int cnt[555];
void edit(int n, int x){
    for(int i=2; i*i<=n; i++){
        while(n % i == 0){
            cnt[i] += x;
            n /= i;
        }
    }
    if(n > 1) cnt[n] += x;
}

void solve(int n, int k){
    fo(i, n - k + 1, n) edit(i, 1);
    fo(i, 2, k) edit(i, -1);
    int res = 1;
    fo(i, 2, 500){
        res *= cnt[i] + 1;
    }
    cout << res;
    fo(i, 2, 500) cnt[i] = 0;
}

void LonggVuz(){
    int n, k;
    while(cin >> n >> k) solve(n, k), el;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int o = 1; //cin >> o;
    while(o){
        LonggVuz();
        if(--o) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
    return (0 ^ 0);
}
