// LonggVuz
#include<bits/stdc++.h>
using namespace std;
// Think twice, code once ^.^
void End(){
    cerr << "=> Smoothly Finished! Time taken: ";
    cerr << (0.001 * clock()) << "s" << string(25, '\t');
}
#define Sonic() cin.tie(NULL) -> sync_with_stdio(false);
#define fix(x) fixed << setprecision(x)
#define all(x) begin(x), end(x)
#define len(x) (int)x.size()
#define gel(x) getline(cin >> ws, x)
#define ms(a, x) memset(a, x, sizeof(a))
#define bit(n, x) (n >> x & 1)
#define pb push_back
#define is insert
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e5 + 7;

int mx[mxn];

void LonggVuz(){
    int n; cin >> n;
    int a[n+5];
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    mx[n] = a[n];
    for(int i=n-1; i>=1; i--){
        mx[i] = max(mx[i + 1], a[i]);
    }
    int res = 0, j = 2;
    for(int i=1; i<=n; i++){
        while(j <= n and mx[j] > a[i]) ++j;
        res = max(res, j - i - 1);
        if(j > n) break;
    }
    if(res) cout << res << el;
    else cout << "-1\n";
}

signed main(){
    Sonic();
    
    int TC = 1; cin >> TC;
    while(TC--) LonggVuz();
    
    End();
}
