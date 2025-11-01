// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LonggVuz
#include <LonggVuz.h>
#else
#define debug(...)
#endif

template<class X, class Y> bool maxi(X &a, const Y &b){ return b > a ? a = b, 1 : 0; }
template<class X, class Y> bool mini(X &a, const Y &b){ return b < a ? a = b, 1 : 0; }

#define el cout << '\n'
#define fup(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define fdn(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int32_t i=a; i<=b; i++)
#define fd(i, a, b) for(int32_t i=a; i>=b; i--)
#define out(x) return void(cout << (x))
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define dub double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;



inline void LonggVuz(){
    string a; cin >> a;
    int n = len(a);
    string b = a, c = a;
    char mx = *max_element(all(b));
    fd(i, n - 1, 1) if(b[i] == mx and b[i] >= b[0]){
    	char t = b[i];
    	fd(j, i, 1) b[j] = b[j - 1];
    	b[0] = t;
    	break;
    }
    fo(i, 0, n - 2) if(c[i] < c[i + 1]){
    	char t = c[i];
    	fo(j, i, n - 2) c[j] = c[j + 1];
    	c[n - 1] = t;
    	break;
    }
    // debug(b, c);
    cout << max(b, c);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; if(1) cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
