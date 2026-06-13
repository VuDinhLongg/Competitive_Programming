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
    int n; vec<vec<vec<int>>> f;
    fenwick(int _n){
        n = _n; f.resize(n + 1, vec<vec<int>>(n + 1, vec<int>(n + 1)));
    }
    int sum(int a, int b){ return a + b; }
    void upd(int x, int y, int z, int v){
        for(int i=x; i<=n; i+=i&-i){
            for(int j=y; j<=n; j+=j&-j){
                for(int k=z; k<=n; k+=k&-k){
                    f[i][j][k] += v;
                }
            }
        }
    }
    int get(int x, int y, int z){
        int s = 0;
        for(int i=x; i>=1; i-=i&-i){
            for(int j=y; j>=1; j-=j&-j){
                for(int k=z; k>=1; k-=k&-k){
                    s += f[i][j][k];
                }
            }
        }
        return s;
    }
};

void LonggVuz(){
    int n, q; cin >> n >> q;
    fenwick f(n);
    int a[n+1][n+1][n+1] = {};
    while(q--){
        string s; cin >> s;
        if(s == "UPDATE"){
            int x, y, z, v; cin >> x >> y >> z >> v;
            f.upd(x, y, z, -a[x][y][z] + v);
            a[x][y][z] = v;
        }else{
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            int res = f.get(x2, y2, z2);
            res -= f.get(x1 - 1, y2, z2) + f.get(x2, y1 - 1, z2) + f.get(x2, y2, z1 - 1);
            res += f.get(x1 - 1, y1 - 1, z2) + f.get(x2, y1 - 1, z1 - 1) + f.get(x1 - 1, y2, z1 - 1);
            res -= f.get(x1 - 1, y1 - 1, z1 - 1);
            cout << res; el;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
