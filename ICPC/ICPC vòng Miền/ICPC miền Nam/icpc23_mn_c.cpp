// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
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
const int mxn = 1e6 + 7;

struct node{
    int x, y, z;
    bool operator < (const node &o) const {
        if(x == o.x){
            if(y == o.y) return z < o.z;
            return y < o.y;
        }
        return x < o.x;
    }
};

#define pii pair<int, int>
#define pip pair<int, pii>
#define ppi pair<pii, int>
#define fi first
#define se second

int n, k;
node a[1001];
map<int, set<pii>> mp;

inline void LonggVuz(){
    cin >> n >> k;
    fo(i, 1, k){
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    fo(i, 1, k) if(a[i].z > 0){
        mp[a[i].z].insert({a[i].x, a[i].y});
    }
    int res = 0;
    for(auto &[v, s] : mp){
        int cnt = 0;
        for(auto [i, j] : s){
            if(i == 0) ++cnt;
        }
        res += len(s) * n - cnt * (len(s) - cnt);
    }
    debug(res);
    fo(i, 1, k) if(a[i].z == 0){
        int cnt = 0;
        for(auto &[v, s] : mp){
            if(s.count({a[i].x, 0}) or s.count({0, a[i].y})){
                ++cnt;
            }
        }
        res += n - cnt;
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
