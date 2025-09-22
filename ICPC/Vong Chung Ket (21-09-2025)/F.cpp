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

int n, cur, cs[] = {3, 5, 7}, res;

bool check(){
    string s = to_string(cur);
    int c3 = 0, c5 = 0, c7 = 0;
    for(char &c : s){
        c3 += c == '3';
        c5 += c == '5';
        c7 += c == '7';
    }
    return c3 and c5 and c7;
}

void run(){
    if(cur > n) return;
    if(check()) ++res;
    for(int &d : cs){
        cur = cur * 10 + d;
        run();
        cur = (cur - d) / 10;
    }
}

void LonggVuz(){
    cin >> n;
    run();
    cout << res;
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
