// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <LonggVuz.h>
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
#define dub double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;



inline void LonggVuz(){
    string a; cin >> a;
    map<char, int> cnt;
    for(char &c : a) ++cnt[c];
    fo(i, 0, 999) if(i % 8 == 0){
        map<char, int> need;
        string s = to_string(i);
        for(char &c : s) ++need[c];
        if(len(a) >= 3) need[0] += 3 - len(s);
        bool ok = 1;
        for(auto &[x, y] : need){
            if(cnt[x] < y){
                ok = 0; break;
            }
        }
        if(ok){
            out("YES");
        }
    }
    cout << "NO";
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
