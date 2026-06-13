// LonggVuz - AC > 0.9s
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

#define i128 __int128_t
string value(i128 n){
    if(n == 0) return "0";
    string s = "";
    bool neg = 0;
    if(n < 0) neg = 1, n = -n;
    while(n) s.pub(n % 10 + '0'), n /= 10;
    if(neg) s.push_back('-');
    reverse(all(s));
    return s;
}

#define bit(n, i) ((n) >> (i) & 1)
#define cnt1(n) __builtin_popcountll(n)
#define clz(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctzll(n)

i128 num(string &a){
    i128 r = 0;
    for(char &c : a) r = r * 10 + c - '0';
    return r;
}

inline void LonggVuz(){
    string p, q; cin >> p >> q;
    short n = len(p), m = len(q);
    i128 vp = num(p), vq = num(q);
    int lim = 1 << n;
    i128 r1 = vp, r2 = vq;
    fo(mask, 1, lim - 1){
        i128 tu = 0;
        vec<short> ftu(10);
        int aim = 0;
        fo(i, 0, n - 1){
            if(bit(mask, i)){
                tu = tu * 10 + (p[i] - '0');
            }else{
                ++aim;
                ++ftu[p[i] - '0'];
            }
        }
        if(tu >= r1 or tu == 0 or ((i128)tu * vq) % vp > 0) continue;
        i128 mau = (i128)tu * vq / vp, mmau = mau;
        short id = m - 1, cur = 0;
        vec<short> fmau(10);
        bool ok = 1;
        while(mmau){
            char c = mmau % 10 + '0';
            while(id >= 0 and q[id] != c){
                ++cur;
                ++fmau[q[id] - '0'];
                --id;
            }
            if(id < 0){
                ok = 0; break;
            }
            --id;
            mmau /= 10;
        }
        if(ok == 0) continue;
        fd(i, id, 0) if(q[i] != '0'){
            ++cur;
            ++fmau[q[i] - '0'];
        }
        if(cur > aim) continue;
        fd(i, id, 0) if(q[i] == '0'){
            if(cur == aim) break;
            ++cur;
            ++fmau[q[i] - '0'];
        }
        fo(i, 0, 9) if(ftu[i] != fmau[i]){
            ok = 0; break;
        }
        if(ok == 0) continue;
        r1 = tu;
        r2 = mau;
    }
    cout << value(r1) << ' ' << value(r2);
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
