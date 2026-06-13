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
const int mxn = 1e5 + 7;

#define pq priority_queue
#define pe pair<int, int>
#define fi first
#define se second
int n, dx[mxn], dy[mxn];
pe a[mxn];

int dis(pe x, pe y){
    return abs(x.fi - y.fi) + abs(x.se - y.se);
}

void LonggVuz(){
    cin >> n;
    fo(i, 1, n){
        cin >> a[i].fi >> a[i].se;
        dx[i] = a[i].fi + a[i].se;
        dy[i] = a[i].fi - a[i].se;
    }
    pq<int> mxx, mxy;
    pq<int, vec<int>, greater<int>> mix, miy;
    fo(i, 1, n){
        mxx.push(dx[i]); mix.push(dx[i]);
        mxy.push(dy[i]); miy.push(dy[i]);
    }
    int max_x = mxx.top(), min_x = mix.top();
    int max_y = mxy.top(), min_y = miy.top();
    vec<int> v;
    fo(i, 1, n){
        if(dx[i] == min_x or dx[i] == max_x) v.pub(i);
        else if(dy[i] == min_y or dy[i] == max_y) v.pub(i);
    }
    int res = oo;
    for(int &id : v){
        int mx1 = -oo, mx2 = -oo;
        int mi1 = oo, mi2 = oo;
        fo(i, 1, n) if(i != id){
            mx1 = max(mx1, dx[i]);
            mx2 = max(mx2, dy[i]);
            mi1 = min(mi1, dx[i]);
            mi2 = min(mi2, dy[i]);
        }
        res = min(res, max(mx1 - mi1, mx2 - mi2));
    }
    cout << res;
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
