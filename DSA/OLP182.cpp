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

int n;

int du(string a){
    int r = 0;
    for(char &c : a) r = (r * 10 + c - '0') % n;
    return r;
}

inline void LonggVuz(){
    cin >> n;
    map<string, int> mp;
    queue<string> q;
    q.push("6"); mp["6"] = du("6");
    q.push("8"); mp["8"] = du("8");
    while(!q.empty()){
        string s = q.front(); q.pop();
        if(len(s) > 200) break;
        if(mp[s] == 0) out(s);
        string x = s + "6";
        if(!mp.count(x)){
            mp[x] = du(x);
            q.push(x);
        }
        string y = "8" + s;
        if(!mp.count(y)){
            mp[y] = du(y);
            q.push(y);
        }
    }
    cout << -1;
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
