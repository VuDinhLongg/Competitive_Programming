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

int cnt[50], len[50];
void pre(){
    cnt[0] = 0; cnt[1] = 1;
    len[0] = 1; len[1] = 1;
    fo(i, 2, 45){
        cnt[i] = cnt[i - 1] + cnt[i - 2];
        len[i] = len[i - 1] + len[i - 2];
    }
}

int cal(int n, int k){
    if(n <= 1) return cnt[n];
    if(k <= len[n - 1]) return cal(n - 1, k);
    return cnt[n - 1] + cal(n - 2, k - len[n - 1]);
}

void LonggVuz(){
    int n, k; cin >> n >> k;
    cout << cal(n, k);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    pre();
    signed orz = 1; cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
