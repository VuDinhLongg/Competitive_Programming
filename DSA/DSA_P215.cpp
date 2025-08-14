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



void LonggVuz(){
    int n, k; cin >> n >> k;
    int a[n+5];
    fo(i, 1, n) cin >> a[i];
    priority_queue<int, vec<int>, greater<int>> q;
    fo(i, 1, n) q.push(a[i]);
    int res = 0;
    while(len(q) > 1){
        if(len(q) >= k){
            int mx = -oo, mi = oo, sum = 0;
            fo(i, 1, k){
                int t = q.top(); q.pop();
                mx = max(mx, t);
                mi = min(mi, t);
                sum += t;
            }
            q.push(sum);
            res += mx - mi;
        }else{
            int mx = -oo, mi = oo, sum = 0;
            while(!q.empty()){
                int t = q.top(); q.pop();
                mx = max(mx, t);
                mi = min(mi, t);
                sum += t;
            }
            q.push(sum);
            res += mx - mi;
        }
    }
    cout << q.top(), el;
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
