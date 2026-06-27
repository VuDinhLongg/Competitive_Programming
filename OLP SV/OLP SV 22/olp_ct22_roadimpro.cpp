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
#define mxn 2007
#define ai3 array<int, 3>
#define ai4 array<int, 4>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, q, dp[mxn][mxn][2];
vector<pii> ke[mxn];

void dijkstra(int t){
	fo(u, 2, n) dp[t][u][0] = dp[t][u][1] = 1e9;
	priority_queue<ai3, vector<ai3>, greater<ai3>> pq;
    pq.push({dp[t][1][0], 1, 0});
    while(pq.size()){
    	auto [cur, u, o] = pq.top(); pq.pop();
    	if(cur > dp[t][u][o]) continue;
    	for(auto &[v, w] : ke[u]){
    		if(o){
    			if(mini(dp[t][v][o], dp[t][u][o] + w)){
    				pq.push({dp[t][v][o], v, o});
    			}
    		}else{
    			if(mini(dp[t][v][o], dp[t][u][o] + w)){
    				pq.push({dp[t][v][o], v, o});
    			}
    			if(t < w and mini(dp[t][v][1], dp[t][u][o] + t)){
    				pq.push({dp[t][v][1], v, 1});
    			}
    		}
    	}
    }
}

inline void LonggVuz(){
    cin >> n >> m >> q;
    rep(i, m){
    	int u, v, w; cin >> u >> v >> w;
    	ke[u].push_back({v, w});
    }
    fo(t, 1, 2000) dijkstra(t);
    while(q--){
    	int s, t0; cin >> s >> t0;
    	cout << min(dp[t0][s][0], dp[t0][s][1]), el;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
