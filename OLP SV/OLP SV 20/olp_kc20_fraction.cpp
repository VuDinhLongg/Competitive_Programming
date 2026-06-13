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

int spf[mxn], cnta[mxn], cntb[mxn];
vector<int> p;

inline void LonggVuz(){
    for(int &i : p) cnta[i] = cntb[i] = 0;
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    bool one = 1;
    rep(i, n) if(b[i] > 1){
    	one = 0; break;
    }
    if(one) out("finite");
    rep(i, n){
    	while(a[i] > 1){
    		++cnta[spf[a[i]]];
    		a[i] /= spf[a[i]];
    	}
    }
    rep(i, n){
    	while(b[i] > 1){
    		++cntb[spf[b[i]]];
    		b[i] /= spf[b[i]];
    	}
    }
    bool ok = 1, o = 0;
    for(int &i : p){
    	if(cnta[i] < cntb[i]){
    		ok = 0;
    	}
    	if(cnta[i] < cntb[i] and i != 2 and i != 5){
    		o = 1;
    	}
    }
    if(ok) out("finite");
    if(o) out("repeating");
    out("finite");
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    fo(i, 2, 1e6) if(spf[i] == 0)
    	for(int j=i; j<=1e6; j+=i) if(spf[j] == 0) spf[j] = i;
    fo(i, 2, 1e6) if(spf[i] == i) p.push_back(i);
    signed o = 1; if(1) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
