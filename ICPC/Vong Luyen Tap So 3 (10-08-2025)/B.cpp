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

int n, a[mxn], pf[mxn];

bool check(int mid){
    fo(i, 1, n - mid + 1){
        int cur = pf[i + mid - 1] ^ pf[i - 1];
        if(cur < a[i - 1] or cur > a[i + mid]) return 1;
    }
    return 0;
}

void LonggVuz(){
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    a[0] = -oo; a[n + 1] = oo;
    int res = oo;
    fo(i, 1, n){
        int cur = 0;
        fd(j, i, 1){
            int le = i - j + 1;
            if(le >= res) break;
            cur ^= a[j];
            int mx = 0;
            fo(k, i + 1, n){
                int ri = k - i;
                if(le + ri - 2 >= res) break;
                mx ^= a[k];
                if(mx < cur){
                    res = min(res, le + ri - 2);
                    break;
                }
            }
        }
    }
    cout << (res < oo ? res : -1);
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
