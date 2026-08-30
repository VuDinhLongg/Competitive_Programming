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
#define rep(i, n) fo(i, 0, n - 1)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 1'000'007
#define ai3 array<int, 3>
#define ai4 array<int, 4>
#define pii pair<int, int>
#define fi first
#define se second

struct node{
	int x, y, w;
};

int n;
node a[1005];
map<pii, vector<pii>> mp;

ai3 trung_truc(pii &p){
	auto [i, j] = p;
	int A = a[i].x - a[j].x;
	int B = a[i].y - a[j].y;
	int sx = a[i].x + a[j].x;
	int sy = a[i].y + a[j].y;
	int o1 = A * 2;
	int o2 = B * 2;
	int o3 = - A * sx - B * sy;
	int g = gcd(gcd(abs(o1), abs(o2)), abs(o3));
	if(g){ o1 /= g; o2 /= g; o3 /= g; }
	if(o1 < 0 or (o1 == 0 and o2 < 0)) return {-o1, -o2, -o3};
	return {o1, o2, o3};
}

ai3 duong_thang(pii &p){
	auto [i, j] = p;
	int A = a[i].x - a[j].x;
	int B = a[i].y - a[j].y;
	int o1 = B;
	int o2 = -A;
	int o3 = - B * a[i].x + A * a[i].y;
	int g = gcd(gcd(abs(o1), abs(o2)), abs(o3));
	if(g){ o1 /= g; o2 /= g; o3 /= g; }
	if(o1 < 0 or (o1 == 0 and o2 < 0)) return {-o1, -o2, -o3};
	return {o1, o2, o3};
}

inline void LonggVuz(){
	cin >> n;
	fo(i, 1, n){
		cin >> a[i].x >> a[i].y >> a[i].w;
	}
	sort(a+1, a+n+1, [](node &u, node &v){
		if(u.y == v.y) return u.x < v.x;
		return u.y < v.y;
	});
	// fo(i, 1, n) dbg(a[i].x, a[i].y, a[i].w);
	fo(i, 1, n) fo(j, i + 1, n){
		int dx = a[i].x - a[j].x;
		int dy = a[i].y - a[j].y;
		if(dx and dy){
			int g = gcd(dx, dy);
			dx /= g;
			dy /= g;
		}else if(dx){
			dx = -1;
		}else if(dy){
			dy = -1;
		}
		mp[{dx, dy}].push_back({i, j});
	}
	int res = -1;
	for(auto &[hs, vt] : mp){
		vector<ai4> tmp;
		fo(i, 0, vt.size() - 1){
			auto [o1, o2, o3] = trung_truc(vt[i]);
			tmp.push_back({o1, o2, o3, i});
		}
		sort(all(tmp));
		int i = 0;
		while(i < tmp.size()){
			int j = i;
			vector<int> pos;
			while(j < tmp.size() and tmp[i][0] == tmp[j][0] and tmp[i][1] == tmp[j][1] and tmp[i][2] == tmp[j][2]){
				pos.push_back(tmp[j][3]);
				++j;
			}
			map<ai3, int> dp;
			for(int &p : pos){
				auto [o1, o2, o3] = duong_thang(vt[p]);
				maxi(dp[{o1, o2, o3}], a[vt[p].fi].w + a[vt[p].se].w);
			}
			int mx1 = 0, mx2 = 0;
			for(auto &[u, v] : dp){
				if(v > mx1){
					mx2 = mx1;
					mx1 = v;
				}else maxi(mx2, v);
			}
			if(mx1 and mx2) maxi(res, mx1 + mx2);
			i = j;
		}
	}
	cout << res;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	#define name "LonggVuz"
	if(fopen(name".inp", "r")){
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}