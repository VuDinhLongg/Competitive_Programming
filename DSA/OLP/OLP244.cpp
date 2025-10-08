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
#define out(x) return void(cout << (x));
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

struct node{
    int op, cl;
};

int n, q;
string s;
node seg[mxn * 4];

node merge(node x, node y){
    int m = min(x.op, y.cl);
    return {x.op + y.op - m, x.cl + y.cl - m};
}

void upd(int id, int l, int r, int i, int x){
    if(l == r){
        if(x) seg[id] = {1, 0};
        else seg[id] = {0, 1};
        return;
    }
    int m = l + r >> 1;
    if(i <= m) upd(id * 2, l, m, i, x);
    else upd(id * 2 + 1, m + 1, r, i, x);
    seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

node get(int id, int l, int r, int u, int v){
    if(r < u or v < l) return {0, 0};
    if(u <= l and r <= v) return seg[id];
    int m = l + r >> 1;
    return merge(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

void LonggVuz(){
    cin >> n >> q >> s;
    s.insert(begin(s), ' ');
    fo(i, 1, n){
        int x = s[i] == '(' ? 1 : 0;
        upd(1, 1, n, i, x);
    }
    while(q--){
        int t, l, r; cin >> t >> l >> r;
        if(t == 1){
            if(s[l] == s[r]) continue;
            swap(s[l], s[r]);
            upd(1, 1, n, l, (s[l] == '(' ? 1 : 0));
            upd(1, 1, n, r, (s[r] == '(' ? 1 : 0));
        }else{
            node res = get(1, 1, n, l, r);
            if(res.op == 0 and res.cl == 0) cout << "Yes\n";
            else cout << "No\n";
        }
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
