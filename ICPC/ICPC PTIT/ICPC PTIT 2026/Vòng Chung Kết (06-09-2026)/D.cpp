#include <bits/stdc++.h>
using namespace std;

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define rep(i, n) fo(i, 0, n - 1)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define int long long
#define mxn 300'007

struct FenwickTree{
    int n; vector<int> bit;
    FenwickTree(){}
    FenwickTree(int _n){
        n = _n;
        bit.assign(n + 5, 0);
    }
    void update(int x, int v){
        for(; 1 <= x and x <= n; x += x & -x) maxi(bit[x], v);
    }
    int query(int x){
        int r = 0;
        for(; 1 <= x and x <= n; x -= x & -x) maxi(r, bit[x]);
        return r;
    }
    int query(int l, int r){
        return l <= r ? query(r) - query(l - 1) : 0;
    }
};

int n;
pair<int, int> a[mxn];

inline void solve(){
    cin >> n;
    fo(i, 1, n) cin >> a[i].first;
    fo(i, 1, n) cin >> a[i].second;
    sort(a+1, a+n+1);
    int res = 1;
    FenwickTree bit(n);
    fo(i, 1, n){
		int x = bit.query(a[i].second - 1);
		maxi(res, x + 1);
		bit.update(a[i].second, x + 1);
    }
    cout << res + n;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #define name "icpc"
    if(fopen(name".inp", "r")){
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    
    int o = 1; ///cin >> o;
    while(o --> 0) solve();
}