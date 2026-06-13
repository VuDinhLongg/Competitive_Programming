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
const int mxm = 5e6 + 7;

struct node{
    int l, r, cnt, sum;
    node(){ l = r = cnt = sum = 0; }
    node(int _l, int _r, int _cnt, int _sum){
        l = _l; r = _r;
        cnt = _cnt; sum = _sum;
    }
};

struct qvat{
    int l, r, p;
};

int n, m, ver[mxn], nver, val[mxn], stt;
vec<int> add[mxn], del[mxn];
node seg[mxm];
vec<qvat> mst;

int upd(int id, int l, int r, int pos, int cnt, int sum){
    int cur = ++stt;
    seg[cur] = seg[id];
    seg[cur].cnt += cnt;
    seg[cur].sum += sum;
    if(l == r) return cur;
    int mid = l + r >> 1;
    if(pos <= mid){
        seg[cur].l = upd(seg[cur].l, l, mid, pos, cnt, sum);
    }else{
        seg[cur].r = upd(seg[cur].r, mid + 1, r, pos, cnt, sum);
    }
    return cur;
}

int get(int id, int l, int r, int e){
    if(e == 0) return 0;
    if(l == r){
        // debug(l, r, seg[id].sum);
        if(e <= seg[id].cnt) return e * seg[id].sum / seg[id].cnt;
        return seg[id].sum;
    }
    int mid = l + r >> 1;
    if(seg[seg[id].l].cnt > e){
        int res = get(seg[id].l, l, mid, e);
        // debug(l, r, res);
        return res;
    }
    int res = seg[seg[id].l].sum + get(seg[id].r, mid + 1, r, e - seg[seg[id].l].cnt);
    // debug(l, r, seg[seg[id].l].sum, res);
    return res;
}

inline void LonggVuz(){
    cin >> n >> m;
    vec<int> zip;
    fo(i, 1, n){
        int l, r, p; cin >> l >> r >> p;
        mst.pub({l, r, p});
        zip.pub(p);
    }
    sort(all(zip));
    zip.erase(unique(all(zip)), end(zip));
    for(auto &[l, r, p] : mst){
        int op = p;
        p = lower_bound(all(zip), p) - begin(zip) + 1;
        val[p] = op;
        add[l].pub(p);
        del[r + 1].pub(p);
    }
    fo(i, 1, m){
        ver[i] = ver[i - 1];
        for(int &p : add[i]){
            ver[i] = upd(ver[i], 1, n, p, 1, val[p]);
        }
        for(int &p : del[i]){
            ver[i] = upd(ver[i], 1, n, p, -1, -val[p]);
        }
    }
    int cur = 1;
    fo(it, 1, m){
        int t, d, a, f; cin >> t >> d >> a >> f;
        int e = 1 + (d * cur + a) % f;
        debug(e);
        int res = get(ver[t], 1, n, e);
        cout << res, el;
        cur = res;
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
