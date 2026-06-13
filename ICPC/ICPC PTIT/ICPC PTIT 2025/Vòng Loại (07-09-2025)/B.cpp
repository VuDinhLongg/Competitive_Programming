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
const int mxn = 1e5 + 7;

int n, m, a[mxn], del[mxn];

void xoa(int n){
    for(int i=2; i*i<=n; i++){
        if(n % i == 0){
            del[i] = del[n / i] = 1;
        }
    }
    if(n > 1) del[n] = 1;
}

void LonggVuz(){
    cin >> n >> m;
    fo(i, 1, n){
        cin >> a[i];
        if(!del[a[i]]) xoa(a[i]);
    }
    vec<int> res;
    fo(i, 1, m) if(!del[i]){
        bool ok = 1;
        for(int j=2; j*j<=i; j++){
            if(i % j == 0){
                if(del[j] or del[i / j]){
                    ok = 0; break;
                }
            }
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
