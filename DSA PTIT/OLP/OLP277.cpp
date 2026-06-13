// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LonggVuz
#include <LonggVuz.h>
#else
#define debug(...)
#define print(...)
#endif

template<class X, class Y> bool maxi(X &a, const Y &b){ return b > a ? a = b, 1 : 0; }
template<class X, class Y> bool mini(X &a, const Y &b){ return b < a ? a = b, 1 : 0; }

#define el cout << '\n'
#define fup(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define fdn(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
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
const int mxn = 1e6 + 7;

#define pii pair<int, int>
#define ii pair<int, int>
#define pip pair<int, pii>
#define ppi pair<pii, int>
#define fi first
#define se second

int b, k, sx, sy, gx, gy, st, en;
int dp[36];
vec<int> vx, vy;
vec<pii> dinh, ke[36];

int dis(pii &p1, pii &p2){
    auto &[x, y] = p1;
    auto &[z, t] = p2;
    if(x == z){
        return 1ll * abs(y - t) * (x % b == 0 ? 1 : k);
    }
    return 1ll * abs(x - z) * (y % b == 0 ? 1 : k);
}

void dijkstra(){
    fo(i, 0, 35) dp[i] = oo;
    queue<int> q;
    q.push(st);
    dp[st] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u == en) continue;
        for(auto &[v, w] : ke[u]){
            if(dp[u] + w < dp[v]){
                dp[v] = dp[u] + w;
                q.push(v);
            }
        }
    }
    cout << dp[en], el;
}

inline void LonggVuz(){
    cin >> b >> k >> sx >> sy >> gx >> gy;
    vx.pub(sx); vx.pub(gx);
    vy.pub(sy); vy.pub(gy);
    fo(i, 0, 1){
        vx.pub((sx / b + i) * b);
        vx.pub((gx / b + i) * b);
        vy.pub((sy / b + i) * b);
        vy.pub((gy / b + i) * b);
    }
    fo(i, 0, len(vx) - 1) fo(j, 0, len(vy) - 1){
        dinh.pub({vx[i], vy[j]});
    }
    sort(all(dinh));
    dinh.erase(unique(all(dinh)), end(dinh));
    fo(i, 0, len(dinh) - 1) fo(j, i + 1, len(dinh) - 1){
        if(dinh[i].fi == dinh[j].fi or dinh[i].se == dinh[j].se){
            int d = dis(dinh[i], dinh[j]);
            ke[i].pub({j, d});
            ke[j].pub({i, d});
        }
    }
    st = lower_bound(all(dinh), make_pair(sx, sy)) - begin(dinh);
    en = lower_bound(all(dinh), make_pair(gx, gy)) - begin(dinh);
    dijkstra();
    vx.clear();
    vy.clear();
    dinh.clear();
    fo(i, 0, 35) ke[i].clear();
}

signed main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    
    signed hehe = 1; if(1) cin >> hehe;
    for(signed hihi = 1; hihi <= hehe; ++hihi){
        print(hihi);
        LonggVuz();
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
