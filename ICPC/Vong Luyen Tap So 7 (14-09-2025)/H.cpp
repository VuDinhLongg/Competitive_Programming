// LonggVuz
#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<LonggVuz.h>
#else
#define debug(...)
#endif

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
#define float double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

#define bit(n, i) ((n) >> (i) & 1)
#define i128 __int128_t
int n, p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};

int check(i128 a, int b){
    i128 r = 1;
    while(b){
        if(a > n) return 0;
        if(b & 1){
            r *= a;
            if(r > n) return 0;
        }
        a *= a; b /= 2;
    }
    return 1;
}

int cal(int m){
    int l = 1, r = sqrtl(n) + 1;
    while(r - l > 1){
        int mid = l + r >> 1;
        if(check(mid, m)) l = mid;
        else r = mid;
    }
    return l - 1;
}

void LonggVuz(){
    cin >> n;
    int res = 1;
    int lim = 1 << 18;
    fo(mask, 1, lim - 1){
        int t = 1;
        fo(i, 0, 17) if(bit(mask, i)) t *= p[i];
        int cnt = __builtin_popcount(mask);
        if(cnt & 1){
            int c = cal(t);
            res += c;
        }else{
            int c = cal(t);
            res -= c;
        }
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("longgvuz.inp", "r", stdin); freopen("longgvuz.out", "w", stdout);
    signed orz = 1; if(false) cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
