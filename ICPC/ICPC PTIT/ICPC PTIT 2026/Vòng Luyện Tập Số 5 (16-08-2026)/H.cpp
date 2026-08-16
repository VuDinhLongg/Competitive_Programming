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

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 100'007

struct FenwickTree{
	int n; vector<int> bit;
	FenwickTree(){}
	FenwickTree(int _n){
		n = _n;
		bit.assign(n + 5, 0);
	}
	void update(int x, int v){
		for(; 1 <= x and x <= n; x += x & -x) bit[x] += v;
	}
	int query(int x){
		int r = 0;
		for(; 1 <= x and x <= n; x -= x & -x) r += bit[x];
		return r;
	}
	int query(int l, int r){
		return l <= r ? query(r) - query(l - 1) : 0;
	}
};

int n, q, cnt[26], seg[mxn * 4], cur[26];
string s;
FenwickTree bit[26];

void update(int id, int l, int r, int i, int x){
	if(l == r){
		seg[id] += x; return;
	}
	int m = l + r >> 1;
	if(i <= m) update(id * 2, l, m, i, x);
	else update(id * 2 + 1, m + 1, r, i, x);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

int query(int id, int l, int r, int u, int v){
	if(r < u or v < l) return 0;
	if(u <= l and r <= v) return seg[id];
	int m = l + r >> 1;
	return query(id * 2, l, m, u, v) + query(id * 2 + 1, m + 1, r, u, v);
}

inline void LonggVuz(){
	cin >> n >> s >> q;
	s = " " + s;
	fo(i, 0, 25) bit[i] = FenwickTree(n);
	fo(i, 1, n){
		++cnt[s[i] - 'a'];
		bit[s[i] - 'a'].update(i, +1);
		if(i == 1) update(1, 1, n, i, +1);
		else update(1, 1, n, i, (s[i] >= s[i - 1] ? +1 : -1));
	}
	while(q--){
		int t; cin >> t;
		if(t == 1){
			int i; char c; cin >> i >> c;
			--cnt[s[i] - 'a'];
			bit[s[i] - 'a'].update(i, -1);
			if(i == 1){
				if(2 <= n){
					update(1, 1, n, 2, (s[2] >= s[1] ? -1 : +1));
				}
			}else{
				update(1, 1, n, i, (s[i] >= s[i - 1] ? -1 : +1));
				if(i + 1 <= n) update(1, 1, n, i + 1, (s[i + 1] >= s[i] ? -1 : +1));
			}
			s[i] = c;
			++cnt[s[i] - 'a'];
			bit[s[i] - 'a'].update(i, +1);
			if(i == 1){
				if(2 <= n){
					update(1, 1, n, 2, (s[2] >= s[1] ? +1 : -1));
				}
			}else{
				update(1, 1, n, i, (s[i] >= s[i - 1] ? +1 : -1));
				if(i + 1 <= n) update(1, 1, n, i + 1, (s[i + 1] >= s[i] ? +1 : -1));
			}
		}else{
			int l, r; cin >> l >> r;
			int res = query(1, 1, n, l + 1, r) + 1;
			if(res == r - l + 1){
				int mi = -1, mx = -1;
				fo(i, 0, 25){
					cur[i] = bit[i].query(l, r);
					if(cur[i]){
						if(mi == -1) mi = i;
						mx = i;
					}
				}
				bool ok = 1;
				fo(i, 0, 25) if(mi <= i and i <= mx and cnt[i]){
					if(i == mi or i == mx){
						if(cur[i] > cnt[i]){
							ok = 0; break;
						}
					}else{
						if(cur[i] != cnt[i]){
							ok = 0; break;
						}
					}
				}
				cout << (ok ? "Yes\n" : "No\n");
			}else cout << "No\n";
		}
	}
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}