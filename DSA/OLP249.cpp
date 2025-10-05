// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <LonggVuz.h>
#else
#define debug(...)
#endif

#define el cout << '\n'
#define inc(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define dec(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int32_t i=a; i<=b; i++)
#define fd(i, a, b) for(int32_t i=a; i>=b; i--)
#define out(x) return void(cout << (x))
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define dub double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 5e5 + 7;
const int mxm = 2e6 + 7;

int n, q, a[mxm], pos[mxn];
int f[mxm];

void upd(int x, int v){
    while(x <= 2e6){
        f[x] += v;
        x += x & -x;
    }
}

int get(int x){
    int r = 0;
    while(x >= 1){
        r += f[x];
        x -= x & -x;
    }
    return r;
}

inline void LonggVuz(){
    cin >> n >> q;
    int l = 5e5 + 1;
    int r = l + n - 1;
    fo(i, l, r){
        cin >> a[i];
        pos[a[i]] = i;
        upd(i, 1);
    }
    int res = 0;
    while(q--){
        int x; char c; cin >> x >> c;
        int p = get(pos[x]);
        res += min(p - 1, n - p);
        if(c == 'r'){
            upd(pos[x], -1);
            pos[x] = ++r;
            upd(pos[x], 1);
        }else{
            upd(pos[x], -1);
            pos[x] = --l;
            upd(pos[x], 1);
        }
        fo(i, 1, n) debug(i, pos[i]);
    }
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
