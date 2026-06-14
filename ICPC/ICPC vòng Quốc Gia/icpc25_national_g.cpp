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
#define fix(x) fixed << setprecision(x)
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 300'007
#define ai3 array<int, 3>
#define ai4 array<int, 4>
#define pii pair<int, int>
#define fi first
#define se second

struct FenwickTree{
	int n; vector<int> bit;
	FenwickTree(int _n){
		n = _n; bit.assign(n + 5, 0);
	}
	void add(int x, int val){
		for(; 1 <= x and x <= n; x -= x & -x) bit[x] += val;
	}
	int query(int x){
		int sum = 0;
		for(; 1 <= x and x <= n; x += x & -x) sum += bit[x];
		return sum;
	}
	int query(int l, int r){
		return (l <= r ? query(r) - query(l - 1) : 0);
	}
};

inline void LonggVuz(){
    int n, q; cin >> n >> q;
    FenwickTree sum(n), cnt(n);
    auto update = [&](int len, int x){
    	sum.add(len, x * len);
    	cnt.add(len, x);
    };
    update(n, 1);
    set<ai3> s;
    s.insert({1, n, 0});
    int oo = 1e9;
    while(q--){
    	int t; cin >> t;
    	if(t == 1){
    		int l, r; char c; cin >> l >> r >> c;
    		++l; ++r;
    		int cc = c - 'A';
    		vector<ai3> del, add;
    		add.push_back({l, r, cc});
    		auto it = s.lower_bound({l, -oo, -oo});
    		if(it != s.begin()) --it;
    		auto st = it;
    		while(it != s.end()){
    			auto [L, R, C] = *it;
    			if(L > r) break;
    			if(l <= L and R <= r) del.push_back({L, R, C});
    			else{
    				if(L < l) add.push_back({L, l - 1, C}), del.push_back({L, R, C});
    				if(R > r) add.push_back({r + 1, R, C}), del.push_back({L, R, C});
    			}
    			++it;
    		}
    		for(auto &[L, R, C] : del) if(s.count({L, R, C})){
    			update(R - L + 1, -1);
    			s.erase({L, R, C});
    		}
    		for(auto &[L, R, C] : add) if(!s.count({L, R, C})){
    			update(R - L + 1, 1);
    			s.insert({L, R, C});
    		}
    		it = s.lower_bound({l - 1, -oo, -oo});
    		if(it != s.begin()) --it;
    		while(it != s.end()){
    			if((*it)[0] > r) break;
    			del.clear(); add.clear();
    			auto jt = it;
    			add.push_back(*it);
    			while(jt != s.end() and (*it)[2] == (*jt)[2]){
    				del.push_back(*jt);
    				maxi(add[0][1], (*jt)[1]);
    				++jt;
    			}
	    		for(auto &[L, R, C] : del) if(s.count({L, R, C})){
	    			update(R - L + 1, -1);
	    			s.erase({L, R, C});
	    		}
    			for(auto &[L, R, C] : add) if(!s.count({L, R, C})){
	    			update(R - L + 1, 1);
	    			s.insert({L, R, C});
	    		}
	    		it = jt;
    		}
    		// for(auto [L, R, C] : s) debug(L, R, C); el;
    	}else{
    		int k; cin >> k;
    		cout << sum.query(k + 1) - cnt.query(k + 1) * k, el;
    	}
    	// fo(i, 1, n) debug(i, sum.query(i), cnt.query(i));
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}