// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LonggVuz
#include <LonggVuz.h>
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
#define dub double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e5 + 7;

struct dsu{
    vec<int> p, s;
    dsu(int n){
        p.resize(n + 5); iota(all(p), 0); s.resize(n + 5, 1);
    }
    int get(int u){
        return (u == p[u]) ? (u) : (p[u] = get(p[u]));
    }
    bool uni(int u, int v){
        u = get(u); v = get(v);
        if(u == v) return 0;
        if(u > v) swap(u, v);
        p[v] = u; s[u] += s[v];
        return 1;
    }
    int sz(int u){ return s[get(u)]; }
    bool same(int u, int v){ return get(u) == get(v); }
};

#define pii pair<int, int>
#define fi first
#define se second

struct node{
    int x, y, w;
};

int n, x[mxn], y[mxn];
vec<pii> ke[11];

int cost(int a, int b, int c, int d){
    return (a - c) * (a - c) + (b - d) * (b - d);
}

inline void LonggVuz(){
    cin >> n;
    fo(i, 1, n){
        cin >> x[i] >> y[i];
        ke[y[i]].pub({x[i], i});
    }
    fo(i, 0, 10) sort(all(ke[i]));
    vec<node> canh;
    fo(i, 1, n){
        fo(j, 0, 10){
            int l = -1, r = len(ke[j]);
            while(r - l > 1){
                int m = l + r >> 1;
                if(ke[j][m].fi > x[i]) r = m;
                else l = m;
            }
            if(r < len(ke[j])){
                int k = ke[j][r].se;
                canh.pub({i, k, cost(x[i], y[i], x[k], y[k])});
            }
            if(l >= 0 and ke[j][l].se == i) --l;
            if(l >= 0){
                int k = ke[j][l].se;
                canh.pub({i, k, cost(x[i], y[i], x[k], y[k])});
            }
        }
    }
    sort(all(canh), [&](node &u, node &v){
        return u.w < v.w;
    });
    int res = 0, cnt = 0;
    dsu d(n);
    for(auto &[x, y, w] : canh){
        if(d.uni(x, y)){
            debug(x, y, w);
            res += w;
            ++cnt;
            if(cnt == n - 1) break;
        }
    }
    cout << res;
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
