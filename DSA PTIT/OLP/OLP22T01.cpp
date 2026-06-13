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
const int mxn = 1e5 + 7;

struct fenwick{
    int n; vec<int> f;
    fenwick(int _n){
        n = _n; f.resize(n + 5);
    }
    int sum(int a, int b){ return a + b; }
    void upd(int x, int v){
        for(; x >= 1 ; x -= x & -x) f[x] = sum(f[x], v);
    }
    int get(int x){
        int s = 0;
        for(; x <= n ; x += x & -x) s = sum(s, f[x]);
        return s;
    }
};

void LonggVuz(){
    int n; cin >> n;
    int a[n+5];
    fo(i, 1, n){
        cin >> a[i];
    }
    fenwick f(n);
    int res = 0;
    vec<int> cnt(n + 5);
    fo(i, 1, n){
        int g = f.get(a[i] + 1);
        res += g;
        cnt[a[i]] += g;
        f.upd(a[i], 1);
    }
    vec<int> ans;
    fd(i, n - 1, 0){
        res -= cnt[i];
        ans.pub(res);
    }
    reverse(all(ans));
    for(int &i : ans) cout << i, el;
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
/*
Input:
5
5 2 3 3 0

Output:
0
4
4
5
7
*/
