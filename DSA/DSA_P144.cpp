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
const int mxn = 2e5 + 7;

int n, l, r, a[mxn], pf[mxn];

void LonggVuz(){
    cin >> n >> l >> r;
    fo(i, 1, n) cin >> a[i];
    int res = -oo, id = 1;
    deque<int> q;
    q.push_back(0);
    fo(i, 1, n){
        while(!q.empty() and i - q.front() > r) q.pop_front();
        if(i - l >= 1){
            while(!q.empty() and pf[i - l] < pf[q.back()]) q.pop_back();
            q.push_back(i - l);
        }
        pf[i] = pf[i - 1] + a[i];
        if(!q.empty() and i - q.front() >= l){
            // cout << i << ' ' << q.front(), el;
            res = max(res, pf[i] - pf[q.front()]);
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
