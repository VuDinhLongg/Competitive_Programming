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
#define mxn 1'000'007
#define pii pair<int, int>
#define fi first
#define se second

int n, m, d[404][404], cnt[404][404];
vector<int> g[404];
vector<pii> canh;

void bfs(int s){
	fo(u, 1, n){
		if(u != s){
			d[s][u] = 1e9;
			cnt[s][u] = 0;
		}else{
			d[s][u] = 0;
			cnt[s][u] = 1;
		}
	}
	queue<int> q;
	q.push(s);
	while(len(q)){
		int u = q.front(); q.pop();
		for(int &v : g[u]){
			if(mini(d[s][v], d[s][u] + 1)){
				cnt[s][v] = cnt[s][u];
				q.push(v);
			}else if(d[s][v] == d[s][u] + 1){
				cnt[s][v] += cnt[s][u];
			}
		}
	}
}

inline void LonggVuz(){
	cin >> n >> m;
	fo(i, 1, m){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		canh.push_back({u, v});
	}
	fo(u, 1, n) bfs(u);
	for(auto &[u, v] : canh){
		int res = 1e9;
		if(d[1][u] + 1 + d[v][n] > d[1][n]){
			res = d[1][n];
		}else{
			if(cnt[1][u] * cnt[v][n] != cnt[1][n]){
				res = d[1][n];
			}else{
				fo(i, 1, n) if((d[1][u] + 1 + d[v][i] > d[1][i] or cnt[1][u] * cnt[v][i] != cnt[1][i])
								and (d[i][u] + 1 + d[v][n] > d[i][n] or cnt[i][u] * cnt[v][n] != cnt[i][n])){
					mini(res, d[1][i] + d[i][n]);
				}
			}
		}
		cout << (res < 1e9 ? res : -1), el;
	}
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o_o = 1; if(false) cin >> o_o;
	fo(c_c, 1, o_o) orz(c_c), LonggVuz();
	
	cerr << "[exec time = '" << clock() << "ms']";
}