// LonggVuz (C++ 23)
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

#define i128 __int128_t
int x;

int cal(int n){
    int res = 0;
    for(int i=1; i*i<=n; i++){
        if(n % i == 0){
            ++res;
            if(i * i != n) ++res;
        }
    }
    return res;
}

int check(i128 n, int fn){
    i128 res = 1;
    while(fn){
        if(n > x) return 1;
        if(fn & 1){
            res *= n;
            if(res > x) return 1;
        }
        n *= n;
        fn /= 2;
    }
    if(res == x) return 0;
    return -1;
}

void LonggVuz(){
    cin >> x;
    if(x == 1) out(1);
    int res = oo;
    fo(fn, 2, 168){
        int l = 0, r = x + 1;
        while(r - l > 1){
            int mid = l + r >> 1;
            int c = check(mid, fn);
            if(c < 0) l = mid;
            else if(c > 0) r = mid;
            else{
                r = mid;
                break;
            }
        }
        if(r <= x and cal(r) == fn and check(r, fn) == 0){
            res = min(res, r);
        }
    }
    cout << (res < oo ? res : -1);
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
