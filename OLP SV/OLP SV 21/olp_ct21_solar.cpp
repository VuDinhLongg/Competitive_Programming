/*======================
   Author : @LonggVuz
======================*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define orz(...) 2005
#endif

#define el cout << '\n'
#define all(x) begin(x), end(x)
#define len(x) (x).size()
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 1'000'007

int n, q, a[mxn], seg_idx[mxn * 4], seg_sum[mxn * 4];

void update(int id, int l, int r, int i, int p){
	if(l == r){
		seg_idx[id] = i;
		seg_sum[id] = p;
		a[i] = p;
		return;
	}
	int m = l + r >> 1;
	if(i <= m) update(id * 2, l, m, i, p);
	else update(id * 2 + 1, m + 1, r, i, p);
	seg_idx[id] = (a[seg_idx[id * 2]] < a[seg_idx[id * 2 + 1]] ? seg_idx[id * 2] : seg_idx[id * 2 + 1]);
	seg_sum[id] = seg_sum[id * 2] + seg_sum[id * 2 + 1];
}

int get_idx(int id, int l, int r, int u, int v){
	if(r < u or v < l) return 0;
	if(u <= l and r <= v) return seg_idx[id];
	int m = l + r >> 1;
	int idx_l = get_idx(id * 2, l, m, u, v);
	int idx_r = get_idx(id * 2 + 1, m + 1, r, u, v);
	return (a[idx_l] < a[idx_r] ? idx_l : idx_r);
}

int get_sum(int id, int l, int r, int u, int v){
	if(r < u or v < l) return 0;
	if(u <= l and r <= v) return seg_sum[id];
	int m = l + r >> 1;
	return get_sum(id * 2, l, m, u, v) + get_sum(id * 2 + 1, m + 1, r, u, v);
}

inline void LonggVuz(){
    cin >> n >> q;
    a[0] = 1e18;
    fo(i, 1, n){
    	cin >> a[i];
    	update(1, 1, n, i, a[i]);
    }
    int cur = 0;
    while(q--){
    	int t; cin >> t;
    	if(t == 1){
    		int d; cin >> d;
    		cur += d;
    		cur %= n;
    	}else if(t == 2){
    		int l, r, p; cin >> l >> r >> p;
    		if(l > r) swap(l, r);
    		l -= cur; if(l <= 0) l += n;
    		r -= cur; if(r <= 0) r += n;
    		if(l <= r){
	    		int idx = get_idx(1, 1, n, l, r);
	    		update(1, 1, n, idx, p);
	    	}else{
	    		int idx1 = get_idx(1, 1, n, l, n);
	    		int idx2 = get_idx(1, 1, n, 1, r);
	    		int idx = (a[idx1] < a[idx2] ? idx1 : idx2);
	    		update(1, 1, n, idx, p);
	    	}
    	}else{
    		int l, r; cin >> l >> r;
    		if(l > r) swap(l, r);
    		l -= cur; if(l <= 0) l += n;
    		r -= cur; if(r <= 0) r += n;
    		if(l <= r){
    			cout << get_sum(1, 1, n, l, r), el;
    		}else{
    			cout << get_sum(1, 1, n, l, n) + get_sum(1, 1, n, 1, r), el;
    		}
    	}
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
