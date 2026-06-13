// LonggVuz
#include<bits/stdc++.h>
using namespace std;
#define el cout << '\n'
#define inc(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define dec(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int32_t i=a; i<=b; i++)
#define fd(i, a, b) for(int32_t i=a; i>=b; i--)
#define out(x) return void(cout << (x));
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

vec<int> base; int bs = 167;

void pre(int n){
    base.resize(n + 5, 1);
    fo(i, 1, n) base[i] = base[i - 1] * bs % mod;
}

struct Hash{
    vec<int> h;
    Hash(string &str){
        int n = len(str);
        str.insert(begin(str), ' ');
        h.resize(n + 5);
        fo(i, 1, n) h[i] = (h[i - 1] * bs + str[i] - 'a' + 1) % mod;
    }
    int get(int l, int r){
        return (h[r] - h[l - 1] * base[r - l + 1] % mod + mod) % mod;
    }
};

int solve(string &a, string &b, string &c, Hash &ha, Hash &hb, Hash &hc, int n, int m, int k){
    int min_len = oo;
    {
        string res = "";
        {
            bool ok = 0;
            fd(len, min(n, m), 1){
                if(ha.get(n - len + 1, n) == hb.get(1, len)){
                    res = a.substr(1) + b.substr(len + 1);
                    ok = 1; break;
                }
            }
            if(ok == 0) res = a.substr(1) + b.substr(1);
        }
        int p = len(res);
        Hash hr(res);
        {
            bool ok = 0;
            fd(len, min(p, k), 1){
                if(hr.get(p - len + 1, p) == hc.get(1, len)){
                    res += c.substr(len + 1);
                    ok = 1; break;
                }
            }
            if(ok == 0) res += c.substr(1);
        }
        min_len = min(min_len, len(res) - 1);
    }
    {
        string bc = "";
        {
            bool ok = 0;
            fd(len, min(m, k), 1){
                if(hb.get(m - len + 1, m) == hc.get(1, len)){
                    bc = b.substr(1) + c.substr(len + 1);
                    ok = 1; break;
                }
            }
            if(ok == 0) bc = b.substr(1) + c.substr(1);
        }
        int nbc = len(bc);
        Hash hbc(bc);
        string res = a;
        {
            bool ok = 0;
            fd(len, min(n, nbc), 1){
                if(ha.get(n - len + 1, n) == hbc.get(1, len)){
                    res += bc.substr(len + 1);
                    ok = 1; break;
                }
            }
            if(ok == 0) res += bc.substr(1);
        }
        min_len = min(min_len, len(res) - 1);
    }
    return min_len;
}

int solve2(string &a, string &b, Hash &ha, Hash &hb, int n, int m){
    string res = "";
    bool ok = 0;
    fd(len, min(n, m), 1){
        if(ha.get(n - len + 1, n) == hb.get(1, len)){
            res = a.substr(1) + b.substr(len + 1);
            ok = 1; break;
        }
    }
    if(ok == 0) res = a.substr(1) + b.substr(1);
    return len(res);
}

void LonggVuz(){
    pre(5e5);
    string a, b, c; cin >> a >> b >> c;
    int n = len(a), m = len(b), k = len(c);
    Hash ha(a), hb(b), hc(c);
    {
        fo(i, 1, n - m + 1){
            if(ha.get(i, i + m - 1) == hb.get(1, m)){
                fo(j, 1, n - k + 1){
                    if(ha.get(j, j + k - 1) == hc.get(1, k)) out(n);
                }
                out(min(solve2(a, c, ha, hc, n, k), solve2(c, a, hc, ha, k, n)));
            }
        }
        fo(i, 1, n - k + 1){
            if(ha.get(i, i + k - 1) == hc.get(1, k)){
                fo(j, 1, n - m + 1){
                    if(ha.get(j, j + m - 1) == hb.get(1, m)) out(n);
                }
                out(min(solve2(a, b, ha, hb, n, m), solve2(b, a, hb, ha, m, n)));
            }
        }
        fo(i, 1, m - k + 1){
            if(hb.get(i, i + k - 1) == hc.get(1, k)){
                fo(j, 1, m - n + 1){
                    if(hb.get(j, j + n - 1) == ha.get(1, n)) out(m);
                }
                out(min(solve2(a, b, ha, hb, n, m), solve2(b, a, hb, ha, m, n)));
            }
        }
        fo(i, 1, m - n + 1){
            if(hb.get(i, i + n - 1) == ha.get(1, n)){
                fo(j, 1, m - k + 1){
                    if(hb.get(j, j + k - 1) == hc.get(1, k)) out(m);
                }
                out(min(solve2(c, b, hc, hb, k, m), solve2(b, c, hb, hc, m, k)));
            }
        }
        fo(i, 1, k - m + 1){
            if(hc.get(i, i + m - 1) == hb.get(1, m)){
                fo(j, 1, k - n + 1){
                    if(hc.get(j, j + n - 1) == ha.get(1, n)) out(k);
                }
                out(min(solve2(c, a, hc, ha, k, n), solve2(a, c, ha, hc, n, k)));
            }
        }
        fo(i, 1, k - n + 1){
            if(hc.get(i, i + n - 1) == ha.get(1, n)){
                fo(j, 1, k - m + 1){
                    if(hc.get(j, j + m - 1) == hb.get(1, m)) out(k);
                }
                out(min(solve2(c, b, hc, hb, k, m), solve2(b, c, hb, hc, m, k)));
            }
        }
    }
    int r1 = solve(a, b, c, ha, hb, hc, n, m, k);
    int r2 = solve(a, c, b, ha, hc, hb, n, k, m);
    int r3 = solve(b, a, c, hb, ha, hc, m, n, k);
    int r4 = solve(b, c, a, hb, hc, ha, m, k, n);
    int r5 = solve(c, a, b, hc, ha, hb, k, n, m);
    int r6 = solve(c, b, a, hc, hb, ha, k, m, n);
    cout << min({r1, r2, r3, r4, r5, r6});
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; //cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
