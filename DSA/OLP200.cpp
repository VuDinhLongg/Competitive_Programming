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
    int n; cin >> n;
    int a[n+5], b[n+5];
    fo(i, 1, n){
        cin >> a[i] >> b[i];
    }
    map<int, int> cntx, cnty;
    vec<int> mx, my;
    fo(i, 1, n){
        ++cntx[a[i]];
        ++cnty[b[i]];
        if(mx.empty() or cntx[a[i]] > cntx[mx.back()]){
            mx.clear();
            mx.pub(a[i]);
        }else if(cntx[a[i]] == cntx[mx.back()]){
            mx.pub(a[i]);
        }
        if(my.empty() or cnty[b[i]] > cnty[my.back()]){
            my.clear();
            my.pub(b[i]);
        }else if(cnty[b[i]] == cnty[my.back()]){
            my.pub(b[i]);
        }
    }
    sort(all(mx));
    sort(all(my));
    int max_x = mx[(len(mx) + 1) / 2 - 1];
    int max_y = my[(len(my) + 1) / 2 - 1];
    int res = oo;
    {
        int ans = 0;
        fo(i, 1, n) ans += abs(a[i] - max_x);
        int c[n+5];
        fo(i, 1, n) c[i] = b[i];
        sort(c+1, c+n+1);
        int mid = (n + 1) / 2;
        fo(i, 1, n){
            if(i < mid){
                ans += abs(c[i] - (c[mid] - (mid - i)));
            }else if(i > mid){
                ans += abs(c[i] - (c[mid] + (i - mid)));
            }
        }
        // cout << ans, el;
        res = min(res, ans);
    }
    {
        int ans = 0;
        fo(i, 1, n) ans += abs(b[i] - max_y);
        int c[n+5];
        fo(i, 1, n) c[i] = a[i];
        sort(c+1, c+n+1);
        int mid = (n + 1) / 2;
        fo(i, 1, n){
            if(i < mid){
                ans += abs(c[i] - (c[mid] - (mid - i)));
            }else if(i > mid){
                ans += abs(c[i] - (c[mid] + (i - mid)));
            }
        }
        // cout << ans, el;
        res = min(res, ans);
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
