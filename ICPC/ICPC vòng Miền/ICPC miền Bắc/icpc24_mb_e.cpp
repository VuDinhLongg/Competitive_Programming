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

int p, q, n;
string s;

struct node{
	int l, r, id;
};

int ten[mxn], suf[mxn], cnt[mxn], ans[mxn], res, sz = 367, dp[mxn];
node tv[mxn];

void zip(vector<int> &a, int l, int r){
	vector<int> v; fo(i, l, r) v.push_back(a[i]); sort(all(v));
	v.erase(unique(all(v)), end(v));
	fo(i, l, r) a[i] = lower_bound(all(v), a[i]) - begin(v) + 1;
}

void zip(int a[], int l, int r){
	vector<int> v; fo(i, l, r) v.push_back(a[i]); sort(all(v));
	v.erase(unique(all(v)), end(v));
	fo(i, l, r) a[i] = lower_bound(all(v), a[i]) - begin(v) + 1;
}

void add(int x){
	res += cnt[x];
	++cnt[x];
}

void del(int x){
	--cnt[x];
	res -= cnt[x];
}

inline void LonggVuz(){
	cin >> p >> s >> q;
	n = len(s);
	s = " " + s;
	if(p == 2 or p == 5){
		fo(i, 1, n){
			cnt[i] = cnt[i - 1];
			dp[i] = dp[i - 1];
			if((s[i] - '0') % p == 0){
				++cnt[i];
				dp[i] += i;
			}
		}
		while(q--){
			int l, r; cin >> l >> r;
			int num = cnt[r] - cnt[l - 1];
			int res = (dp[r] - dp[l - 1]) - num * (l - 1);
			cout << res, el;
		}
	}else{
		ten[0] = 1;
		fo(i, 1, n) ten[i] = ten[i - 1] * 10 % p;
		fd(i, n, 1){
			int d = s[i] - '0';
			suf[i] = (d * ten[n - i] + suf[i + 1]) % p;
		}
		zip(suf, 1, n + 1);
		fo(i, 1, q){
			cin >> tv[i].l >> tv[i].r;
			++tv[i].r;
			tv[i].id = i;
		}
		sort(tv+1, tv+q+1, [&](node &x, node &y){
			if(x.l / sz == y.l / sz){
				if((x.l / sz) & 1) return x.r < y.r;
				return x.r > y.r;
			}
			return x.l < y.l;
		});
		int L = 1, R = 0;
		fo(i, 1, q){
			auto &[l, r, id] = tv[i];
			while(L > l) add(suf[--L]);
			while(R < r) add(suf[++R]);
			while(L < l) del(suf[L++]);
			while(R > r) del(suf[R--]);
			ans[id] = res;
		}
		fo(i, 1, q) cout << ans[i], el;
	}
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}
