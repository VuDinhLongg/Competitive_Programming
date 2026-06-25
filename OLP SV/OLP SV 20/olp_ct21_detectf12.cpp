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

int n, f0, d, f1[mxn], f2[mxn];
int x[mxn], y[mxn];

int dist(int i, int j){
	return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

inline void LonggVuz(){
    cin >> n >> f0 >> d;
    fo(i, 1, n){
    	cin >> x[i] >> y[i];
    }
    int cnt1 = 0;
    fo(i, 1, n) if(i != f0){
    	int di = dist(i, f0);
    	if(di < d * d){
    		++cnt1;
    		f1[i] = 1;
    	}
    }
    int cnt2 = 0;
    fo(i, 1, n) if(i != f0 and f1[i] == 0 and f2[i] == 0){
    	fo(j, 1, n) if(j != f0 and f1[j] == 1){
    		int di = dist(i, j);
    		if(di < d * d){
    			++cnt2;
    			f2[i] = 1;
    			break;
    		}
    	}
    }
    cout << cnt1 << ' ' << cnt2;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
