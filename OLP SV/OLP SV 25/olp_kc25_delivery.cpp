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
#define mxn 1'000'007
#define ai3 array<int, 3>
#define ai4 array<int, 4>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, p, a[mxn], b[mxn];

inline void LonggVuz(){
    cin >> n >> m >> p;
    fo(i, 1, n) cin >> a[i];
    fo(i, 1, m) cin >> b[i];
    vector<pii> c;
    fo(i, 1, n) c.push_back({a[i], 0});
    fo(i, 1, m) c.push_back({b[i], i});
    sort(all(c));
    priority_queue<int, vector<int>, greater<int>> q;
    int cur = 0;
    for(auto &[x, t] : c){
    	if(t == 0){
    		if(cur + 1 > x * p){
    			if(q.empty()) out(-1);
    			q.pop();
    			--cur;
    		}
    		++cur;
    	}else{
    		if(cur + 1 > x * p){
    			if(q.empty()) continue;
    			q.pop();
    			--cur;
    			q.push(t);
    			++cur;
    		}else{
    			q.push(t);
    			++cur;
    		}
    	}
    }
    cout << q.size(), el;
    while(!q.empty()){
    	cout << q.top() << ' ';
    	q.pop();
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}