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
const int mxn = 1e6 + 7;

int n, a[1001], b[1001];

void LonggVuz(){
    cin >> n;
    fo(i, 1, n) cin >> a[i];
    int res = 0;
    fo(p, 1, n){
        fo(i, 1, n) b[i] = a[p] - a[i];
        sort(b+1, b+n+1);
        fo(i, 1, n - 2){
            int j = i + 1, k = n;
            bool found = 0;
            while(j < k){
                if(b[i] + b[j] + b[k] < 0) ++j;
                else if(b[i] + b[j] + b[k] > 0) --k;
                else{
                    found = 1; break;
                }
            }
            if(found){
                ++res;
                break;
            }
        }
    }
    cout << res;
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
