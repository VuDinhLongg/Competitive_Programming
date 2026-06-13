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

int h[5], c[5], a[5][5], hang[5], cot[5], res;

void run(int i, int j){
    // debug(i, j);
    if(i > 3){
        ++res; return;
    }
    fo(x, 1, 30){
        a[i][j] = x;
        hang[i] += x;
        cot[j] += x;
        bool ok = 1;
        if(a[1][1] and a[1][2] and a[1][3]){
            if(hang[1] != h[1]) ok = 0;
        }
        if(a[2][1] and a[2][2] and a[2][3]){
            if(hang[2] != h[2]) ok = 0;
        }
        if(a[3][1] and a[3][2] and a[3][3]){
            if(hang[3] != h[3]) ok = 0;
        }
        if(a[1][1] and a[2][1] and a[3][1]){
            if(cot[1] != c[1]) ok = 0;
        }
        if(a[1][2] and a[2][2] and a[3][2]){
            if(cot[2] != c[2]) ok = 0;
        }
        if(a[1][3] and a[2][3] and a[3][3]){
            if(cot[3] != c[3]) ok = 0;
        }
        if(ok){
            if(j < 3) run(i, j + 1);
            else run(i + 1, 1);
        }
        a[i][j] = 0;
        hang[i] -= x;
        cot[j] -= x;
    }
}

void LonggVuz(){
    fo(i, 1, 3) cin >> h[i];
    fo(i, 1, 3) cin >> c[i];
    run(1, 1);
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; if(false) cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
