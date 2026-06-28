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
#define len(x) (int)(x).size()
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 2'000'007

int n, s, base = 1e6;
vector<int> vx[mxn], vy[mxn];

bool binary_search2(const vector<int> &v, int aim){
	int l = -1, r = len(v);
	while(r - l > 1){
		int mid = l + r >> 1;
		if(v[mid] >= aim) l = mid;
		else r = mid;
	}
	return l >= 0 and v[l] == aim;
}

inline void LonggVuz(){
    cin >> n >> s;
    fo(i, 1, n){
    	int x, y; cin >> x >> y;
    	x += base;
    	y += base;
    	vx[x].push_back(y);
    	vy[y].push_back(x);
    }
    s *= 2;
    vector<int> d;
    for(int i=1; i*i<=s; ++i) if(s % i == 0){
    	d.push_back(i);
    	if(i * i != s) d.push_back(s / i);
    }
    sort(all(d));
    int res = 0;
    fo(x, 0, 2e6) if(vx[x].size()) sort(all(vx[x]));
    fo(y, 0, 2e6) if(vy[y].size()){
    	sort(all(vy[y]));
    	for(int &x : vy[y]){
    		for(int &u : d){
    			if(binary_search(all(vy[y]), x - u)){
    				int v = s / u;
    				if(binary_search(all(vx[x - u]), y + v)) ++res;
    				if(binary_search(all(vx[x - u]), y - v)) ++res;
    			}
    		}
    	}
    	reverse(all(vy[y]));
    	for(int &x : vy[y]){
    		for(int &u : d){
    			if(binary_search2(vy[y], x + u)){
    				int v = s / u;
    				if(binary_search(all(vx[x + u]), y + v)) ++res;
    				if(binary_search(all(vx[x + u]), y - v)) ++res;
    			}
    		}
    	}
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
