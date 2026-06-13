// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LonggVuz
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
const int mxn = 1e5 + 7;
const int mxm = 1e6 + 7;
const int sz = 333;

struct node{
    int l, r, id;
};

int n, q, a[mxn], cnt[mxn], cur, ans[mxm];

void edit(int x){
    cnt[x] ^= 1;
    if(cnt[x] == 0) --cur;
    else ++cur;
}

inline void LonggVuz(){
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    vec<node> tv;
    cin >> q;
    fo(i, 1, q){
        int l, r; cin >> l >> r;
        tv.pub({l, r, i});
    }
    sort(all(tv), [&](node &x, node &y){
        if(x.l / sz == y.l / sz){
            if((x.l / sz) & 1) return x.r > y.r;
            return x.r < y.r;
        }
        return x.l < y.l;
    });
    int l = 1, r = 0;
    for(auto &[le, ri, id] : tv){
        while(l < le) edit(a[l++]);
        while(l > le) edit(a[--l]);
        while(r < ri) edit(a[++r]);
        while(r > ri) edit(a[r--]);
        ans[id] = (r - l + 1 - cur) / 2;
    }
    fo(i, 1, q) cout << ans[i], el;
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
