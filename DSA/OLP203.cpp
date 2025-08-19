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

int val(int i, int j){
    int id = i + j - 1;
    int res = 1 + (id * (id - 1) / 2);
    res = res + j - 1;
    return res;
}

void LonggVuz(){
    int x, y, z; cin >> x >> y >> z;
    {
        cout << val(x, y), el;
    }
    {
        int l = 1, r = 1e5;
        while(r - l > 1){
            int mid = l + r >> 1;
            if(val(mid, 1) <= z) l = mid;
            else r = mid;
        }
        int t = val(l, 1), d = z - t;
        cout << l - d << ' ' << 1 + d;
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
