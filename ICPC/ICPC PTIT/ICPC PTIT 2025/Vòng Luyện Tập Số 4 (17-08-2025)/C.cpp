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
const int mxn = 1e3 + 7;

int n;
char a[mxn][mxn];

void LonggVuz(){
    cin >> n;
    fo(i, 1, n) fo(j, 1, n) cin >> a[i][j];
    fo(i, 1, n) fo(j, 1, n){
        if(j + 5 <= n){
            int x = i, y = j, cnt = 0;
            while(y < j + 6){
                cnt += a[x][y] == '#';
                ++y;
            }
            if(cnt >= 4) out("Yes");
        }
        if(i + 5 <= n){
            int x = i, y = j, cnt = 0;
            while(x < i + 6){
                cnt += a[x][y] == '#';
                ++x;
            }
            if(cnt >= 4) out("Yes");
        }
        if(i + 5 <= n and j + 5 <= n){
            int x = i, y = j, cnt = 0;
            while(x < i + 6 and y < j + 6){
                cnt += a[x][y] == '#';
                ++x; ++y;
            }
            if(cnt >= 4) out("Yes");
        }
        if(i + 5 <= n and j - 5 >= 1){
            int x = i, y = j, cnt = 0;
            while(x < i + 6 and y > j - 6){
                cnt += a[x][y] == '#';
                ++x; --y;
            }
            if(cnt >= 4) out("Yes");
        }
    }
    cout << "No";
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
