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

const int mod = 1e9 + 7;
const int mxn = 6e5 + 7;

#define bit(n, i) (n >> (i) & 1)
int n, q, a[mxn], dem[mxn], ans[mxn], mx = (1 << 19) + 1;
// trie
int child[mxn * 20][2], cnt;

void add(int x){
    int u = 0;
    fd(i, 19, 0){
        bool k = bit(x, i);
        if(child[u][k] == 0){
            child[u][k] = ++cnt;
        }
        u = child[u][k];
    }
}

void LonggVuz(){
    cin >> n >> q;
    fo(i, 1, n){
        cin >> a[i];
        ++dem[a[i]];
    }
    fo(i, 0, mx) if(dem[i] == 0) add(i);
    int cur = 0;
    while(q--){
        int x; cin >> x;
        cur ^= x;
        int res = 0, u = 0;
        fd(i, 19, 0){
            int k = bit(cur, i);
            if(child[u][k]){
                u = child[u][k];
            }else{
                res += 1 << i;
                u = child[u][k ^ 1];
            }
        }
        cout << res, el;
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
