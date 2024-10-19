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

struct mtr{
    int x[11][11];
    mtr(){
        ms(x, 0);
    }
};

int n;
mtr operator * (mtr &a, mtr &b){
    mtr c;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                c.x[i][j] += a.x[i][k] * b.x[k][j];
                c.x[i][j] %= mod;
            }
        }
    }return c;
}

mtr mu(mtr &a, int n, int k){
    mtr res;
    for(int i=1; i<=n; i++) res.x[i][i] = 1;
    while(k){
        if(k % 2){
            res = res * a;
        }k /= 2;
        a = a * a;
    }return res;
}

void LonggVuz(){
    int k; cin >> n >> k;
    mtr a;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a.x[i][j];
        }
    }
    a = mu(a, n, k);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << a.x[i][j] << ' ';
        }cout << el;
    }
}

signed main(){
    Sonic();
    
    int TC = 1; cin >> TC;
    while(TC--) LonggVuz();
    
    End();
}
