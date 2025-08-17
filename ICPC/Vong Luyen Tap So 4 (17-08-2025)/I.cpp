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
#define int uint64_t

const int mod = 1e9 + 7;
const int oo = 1e19 + 7;
const int mxn = 1e6 + 7;

int sum(int n){
    int s = 0;
    while(n){
        s += n % 10;
        n /= 10;
    }
    return s;
}

void LonggVuz(){
    int n, s; cin >> n >> s;
    if(sum(n) <= s) out(0);
    int res = oo;
    string a = to_string(n);
    int pre = 0, cur = 0;
    fo(i, 0, len(a) - 1){
        if(a[i] < '9'){
            int sum = pre + (a[i] - '0') + 1;
            if(sum <= s){
                int so = cur;
                so = so * 10 + (a[i] - '0') + 1;
                while(so < n) so *= 10;
                res = min(res, so - n);
            }
        }
        pre += a[i] - '0';
        cur = cur * 10 + a[i] - '0';
    }
    if(res == oo){
        int ans = 1;
        while(ans < n) ans *= 10;
        res = min(res, ans - n);
    }
    cout << res;
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
