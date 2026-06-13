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

int c[66][66];
void pre(){
    fo(i, 0, 60){
        fo(j, 0, i){
            if(j == 0 or j == i) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

void LonggVuz(){
    pre();
    int a, b, k; cin >> a >> b >> k;
    while(a or b){
        if(a >= 1){
            int cnt = c[a - 1 + b][a - 1];
            if(k <= cnt){
                cout << 'a';
                --a;
            }else{
                cout << 'b';
                --b;
                k -= cnt;
            }
        }else{
            cout << 'b';
            --b;
            k -= 1;
        }
    }
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
