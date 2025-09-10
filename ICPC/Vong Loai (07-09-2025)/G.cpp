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
const int mxn = 2e5 + 7;

struct fenwick{
    int n; vec<int> f, g;
    fenwick(int _n){
        n = _n; f.resize(n + 5); g.resize(n + 5);
    }
    void upd1(int x, int v){
        for(; x >= 1 ; x -= x & -x) g[x] += v;
    }
    void updn(int x, int v){
        for(; x <= n ; x += x & -x) f[x] += v;
    }
    int get1(int x){
        int s = 0;
        for(; x >= 1 ; x -= x & -x) s += f[x];
        return s;
    }
    int getn(int x){
        int s = 0;
        for(; x <= n; x += x & -x) s += g[x];
        return s;
    }
};

int n, m, k;
vec<int> hang[mxn], cot[mxn];

void LonggVuz(){
    cin >> n >> m >> k;
    fo(i, 1, k){
        int x, y; cin >> x >> y;
        hang[x].pub(y);
        cot[y].pub(x);
    }
    fo(i, 1, n) if(!hang[i].empty()) sort(all(hang[i]));
    fo(i, 1, m) if(!cot[i].empty()) sort(all(cot[i]));
    int res = n * m;
    // xu ly cot 1
    int last = n + 1;
    if(!cot[1].empty()) last = cot[1][0];
    if(last == 1) out(0);
    res -= n - last + 1;
    fenwick f(last - 1);
    // xu ly cot 2 -> m
    int lastm = m + 1;
    if(!hang[1].empty()) lastm = hang[1][0];
    vec<char> mark(last);
    fo(c, 2, lastm - 1){
        for(int &x : cot[c]) if(x < last and mark[x] == 0){
            mark[x] = 1;
            f.updn(x, 1);
        }
        if(!cot[c].empty()){
            int id = cot[c][0];
            if(id < last){
                int g = f.get1(last - 1) - f.get1(id - 1) + n - last + 1;
                res -= g;
            }else{
                res -= n - id + 1;
            }
        }
    }
    fo(c, lastm, m){
        for(int &x : cot[c]) if(x < last and mark[x] == 0){
            mark[x] = 1;
            f.updn(x, 1);
        }
        int g = f.get1(last - 1) + n - last + 1;
        res -= g;
    }
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
