// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LonggVuz
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

int len[100];

char get(int id, int n){
    if(id == 0){
        if(n == 1) return 'A';
        return 'C';
    }
    if(n <= len[id - 1]) return get(id - 1, n);
    if(n > len[id - 1] + (id + 2 + 1)){
        return get(id - 1, n - (len[id - 1] + (id + 2 + 1)));
    }
    if(n == len[id - 1] + 1) return 'A';
    return 'C';
}

inline void LonggVuz(){
    len[0] = 3;
    int id = 1;
    while(1){
        len[id] = len[id - 1] * 2 + (id + 2 + 1);
        if(len[id] > 1e9) break;
        ++id;
    }
    int n; cin >> n;
    cout << get(id, n);
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
