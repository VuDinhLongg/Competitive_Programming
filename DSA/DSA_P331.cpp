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

bool nt[mxn];
vec<int> v;

void pre(){
    fo(i, 2, 4e3) if(nt[i] == 0){
        inc(j, i * i, 1e7, i) nt[j] = 1;
    }
    v.pub(2);
    inc(i, 3, 1e7, 2) if(nt[i] == 0) v.pub(i);
}

void LonggVuz(){
    int n; cin >> n;
    for(int &i : v) if(n % i == 0){
        int d = 0;
        while(n % i == 0){
            ++d;
            n /= i;
        }
        cout << i << ' ' << d, el;
        if(n == 1) break;
    }
    if(n > 1) cout << n << ' ' << 1, el;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    pre();
    signed orz = 1; cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
