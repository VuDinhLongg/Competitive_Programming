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
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

int a[15], f[5], cnt[5], res;

inline int get(){
    int mx = -oo, mi = oo;
    fo(i, 1, 4) if(cnt[i] == 3){
        mx = max(mx, f[i]);
        mi = min(mi, f[i]);
    }
    return mx - mi;
}

void run(int id){
    fo(i, 1, 4) if(cnt[i] < 3){
        ++cnt[i];
        f[i] += a[id];
        if(id == 12){
            res = min(res, get());
        }else{
            if(get() < res) run(id + 1);
        }
        --cnt[i];
        f[i] -= a[id];
    }
}

void LonggVuz(){
    fo(i, 1, 12) cin >> a[i];
    res = oo;
    run(1);
    cout << res;
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
