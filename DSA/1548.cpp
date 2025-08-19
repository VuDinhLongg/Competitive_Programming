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

struct fenwick{
    int n; vec<int> f;
    fenwick(int _n){
        n = _n; f.resize(n + 5);
    }
    int sum(int a, int b){ return a + b; }
    void upd(int x, int v){
        for(; x <= n ; x += x & -x) f[x] = sum(f[x], v);
    }
    int get(int x){
        int s = 0;
        for(; x >= 1 ; x -= x & -x) s = sum(s, f[x]);
        return s;
    }
};

void LonggVuz(){
    int q; cin >> q;
    fenwick f(1e6);
    int len = 0;
    while(q--){
        string s; cin >> s;
        if(s == "add"){
            int x; cin >> x;
            f.upd(x, 1);
            ++len;
        }else if(s == "del"){
            int x; cin >> x;
            f.upd(x, -1);
            --len;
        }else{
            int l = 0, r = 1e6;
            while(r - l > 1){
                int mid = l + r >> 1;
                if(f.get(mid) >= (len + 1) / 2) r = mid;
                else l = mid;
            }
            cout << r, el;
        }
    }
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
