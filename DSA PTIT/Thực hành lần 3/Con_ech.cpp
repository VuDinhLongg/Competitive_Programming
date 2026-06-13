// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Legendary Grandmaster
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
const int mxn = 1e6 + 7;

int f[55];
void hehe(){
    f[1] = 1;
    f[2] = 2;
    f[3] = 4;
    for(int i=4; i<=50; i++) f[i] = f[i-1] + f[i-2] + f[i-3];
}

void LonggVuz(){
    int n; cin >> n;
    cout << f[n] << el;
}

signed main(){
    Sonic();
    
    hehe();
    int TC = 1; cin >> TC;
    while(TC--) LonggVuz();
    
    End();
}
