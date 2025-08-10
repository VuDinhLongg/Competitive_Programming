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



void LonggVuz(){
    string a; cin >> a;
    int k; cin >> k;
    int n = len(a);
    int p[n];
    fo(i, 0, n - 1) p[i] = i;
    vec<string> res;
    do{
        string t = "";
        fo(i, 0, n - 1) t.pub(a[p[i]]);
        res.pub(t);
    }while(next_permutation(p, p + n));
    sort(all(res));
    // for(auto &i : res) cout << i, el;
    fo(i, 0, len(res) - 1){
        if(i == 0 or res[i] != res[i - 1]){
            --k; if(k == 0) out(res[i]);
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
