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
#define out(x) return void(cout << (x));
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

void LonggVuz(){
    string a; cin >> a;
    int k; cin >> k;
    int n = len(a);
    Hash h(a);
    set<int> s;
    fo(i, 1, n){
        stack<int> st;
        int level = 0;
        fo(j, i, n){
            if(a[j] == '('){
                st.push(len(st) + 1);
            }else{
                if(st.empty()) break;;
                level = max(level, st.top());
                st.pop();
            }
            if(level > k) break;
            if(level == k and st.empty()){
                debug(i, j, h.get(i, j));
                s.insert(h.get(i, j));
            }
        }
    }
    cout << len(s);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    pre(1e3);
    signed orz = 1; if(1) cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
