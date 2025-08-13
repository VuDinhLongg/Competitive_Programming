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
const int mxn = 1e7 + 7;

bool nt[mxn], ok;
vec<int> v;

void pre(){
    fo(i, 2, 4e3) if(nt[i] == 0){
        inc(j, i * i, 1e7, i) nt[j] = 1;
    }
}

void edit(int n, map<int, int> &mp, int x){
    for(int i=2; i<=1e7 and i*i<=n; i++) if(nt[i] == 0){
        while(n % i == 0){
            mp[i] += x;
            if(mp[i] < 0){
                ok = 0; return;
            }
            n /= i;
        }
    }
    if(n > 1){
        mp[n] += x;
        if(mp[n] < 0) ok = 0;
    }
}

void LonggVuz(){
    pre();
    int n, m; cin >> n >> m;
    map<int, int> cnt;
    fo(i, 1, n){
        int x; cin >> x;
        edit(x, cnt, 1);
    }
    vec<int> res;
    fo(i, 1, m){
        ok = 1;
        map<int, int> mp = cnt;
        fo(j, 1, n){
            int x; cin >> x;
            edit(x, mp, -1);
        }
        if(ok) res.pub(i);
    }
    cout << len(res), el;
    for(int &i : res) cout << i << ' ';
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
