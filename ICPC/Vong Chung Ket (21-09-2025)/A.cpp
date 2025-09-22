// LonggVuz
#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<LonggVuz.h>
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
#define float double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 2e5 + 7;

int n, q;
string s;

void LonggVuz(){
    cin >> n >> q >> s;
    s.insert(begin(s), ' ');
    int res = 0;
    fo(i, 1, n - 2){
        if(s[i] == 'A' and s[i + 1] == 'B' and s[i + 2] == 'C'){
            ++res;
        }
    }
    while(q--){
        int x; char c; cin >> x >> c;
        fo(i, max(x - 2, (int)1), min(x, n - 2)){
            if(s[i] == 'A' and s[i + 1] == 'B' and s[i + 2] == 'C'){
                --res;
            }
        }
        s[x] = c;
        fo(i, max(x - 2, (int)1), min(x, n - 2)){
            if(s[i] == 'A' and s[i + 1] == 'B' and s[i + 2] == 'C'){
                ++res;
            }
        }
        cout << res, el;
    }
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
