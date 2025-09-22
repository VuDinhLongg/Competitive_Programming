// LonggVuz
#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<LonggVuz.h>
#else
#define debug(...)
#endif

#define el cout << '\n'
#define inc(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define dec(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int32_t i=a; i<=b; i++)
#define fd(i, a, b) for(int32_t i=a; i>=b; i--)
#define out(x) return void(cout << (x))
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define float double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

struct fenwick{
    int n; vec<int> f, g;
    fenwick(int _n){
        n = _n; f.resize(n + 5); g.resize(n + 5);
    }
    void upd1(int x, int v){
        for(; x >= 1 ; x -= x & -x) g[x] += v;
    }
    void updn(int x, int v){
        for(; x <= n ; x += x & -x) f[x] += v;
    }
    int get1(int x){
        int s = 0;
        for(; x >= 1 ; x -= x & -x) s += f[x];
        return s;
    }
    int getn(int x){
        int s = 0;
        for(; x <= n; x += x & -x) s += g[x];
        return s;
    }
};

int mu(int a, int b, int m = mod){
    int res = 1;
    while(b){
        a %= m;
        if(b & 1) res = (res * a) % m;
        a *= a; b /= 2;
    }
    return res;
}

int f[mxn], ivf[mxn];
void pre(int n){
    f[0] = 1;
    fo(i, 1, n) f[i] = f[i - 1] * i % mod;
    ivf[n] = mu(f[n], mod - 2);
    fd(i, n, 1) ivf[i - 1] = ivf[i] * i % mod;
}

int C(int n, int k){
    if(n < k) return 0;
    return f[n] * ivf[k] % mod * ivf[n - k] % mod;
}

int n, k, c[mxn][26], cnt, e[mxn];
string a[mxn], s;

void add(string &str, int i){
    int u = 0;
    for(char &kt : str){
        int k = kt - 'a';
        if(c[u][k] == 0) c[u][k] = ++cnt;
        u = c[u][k];
    }
    e[u] = i;
}

void LonggVuz(){
    pre(1e6);
    cin >> n >> k;
    fo(i, 1, n) cin >> a[i];
    cin >> s;
    int m = len(s);
    s = "#" + s;
    sort(a+1, a+n+1);
    fenwick ft(n);
    fo(i, 1, n){
        add(a[i], i);
        ft.updn(i, 1);
    }
    int id = 1, cur = 0, res = 0;
    while(id <= m){
        string t = "";
        int u = 0;
        while(e[u] == 0){
            char kt = s[id++];
            t.pub(kt);
            u = c[u][kt - 'a'];
        }
        int vt = e[u];
        int g = ft.get1(vt - 1);
        debug(vt, t, g);
        res += g * C(n - cur - 1, k - cur - 1) % mod * f[k - cur - 1] % mod;
        res %= mod;
        ++cur;
        ft.updn(vt, -1);
    }
    cout << (res + 1) % mod;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; if(false) cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
