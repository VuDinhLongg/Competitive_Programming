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

#define pe pair<int, int>
#define fi first
#define se second
int n, mx[mxn], mi[mxn];
pe a[mxn];

int dis(pe x, pe y){
    return min(abs(x.fi - y.fi), abs(x.se - y.se));
}

bool check(int x){
    fo(i, 1, n){
        int l = i, r = n + 1;
        while(r - l > 1){
            int mid = l + r >> 1;
            if(a[mid].fi - a[i].fi >= x) r = mid;
            else l = mid;
        }
        if(r <= n){
            if(mx[r] - a[i].se >= x or a[i].se - mi[r] >= x) return 1;
        }else break;
    }
    return 0;
}

void LonggVuz(){
    cin >> n;
    fo(i, 1, n){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1, a+n+1);
    mx[n + 1] = -oo;
    mi[n + 1] = oo;
    fd(i, n, 1){
        mx[i] = max(mx[i + 1], a[i].se);
        mi[i] = min(mi[i + 1], a[i].se);
    }
    int l = 0, r = 1e9 + 1;
    while(r - l > 1){
        int mid = l + r >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
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
