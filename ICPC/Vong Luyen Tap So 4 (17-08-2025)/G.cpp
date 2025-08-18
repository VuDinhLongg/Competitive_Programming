// BidenJR
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

int floor_div(int a, int b){
    if(b < 0) a = -a, b = -b;
    if(a >= 0) return a / b;
    return - ( ( -a + b - 1 ) / b );
}

int floor_sum(int n, int m, int a, int b){
    int ans = 0;
    while(true){
        if(a >= m){
            int q = a / m;
            int tmp = (int)(n - 1) * (int)n / 2;
            tmp *= q;
            ans += (int)tmp;
            a %= m;
        }
        if(b >= m){
            int q = b / m;
            ans += q * n;
            b %= m;
        }
        int y_max = (int)a * n + b;
        if(y_max < m) return ans;
        int n2 = (int)(y_max / m);
        int b2 = (int)(y_max % m);
        int tmp = m;
        m = a;
        a = tmp;
        n = n2;
        b = b2;
    }
}

int solve(int n, int m, int a, int b){
    if(n <= 0) return 0;
    int b_mod = ((b % m) + m) % m;
    int k = floor_div((int)(b - b_mod), (int)m);
    int res = floor_sum(n, m, a, b_mod);
    int add = (int)k * (int)n;
    res += (int)add;
    return res;
}

void LonggVuz(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int diff = c - b;
    int kmax = (d - 1) / diff;
    if(kmax <= 0){
        cout << 0;
        return;
    }
    int t0 = ((-a) % d + d) % d;
    int n = kmax;
    int a1 = c % d;
    int b1 = (int)c - t0;
    int s1 = solve(n, d, a1, b1);
    int a2 = b % d;
    int b2 = (int)b - t0 - 1;
    int s2 = solve(n, d, a2, b2);
    int forb = s1 - s2;
    int ans = (int)kmax - forb;
    if(ans < 0) ans = 0;
    cout << ans;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    signed orz = 1; cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
    return 0;
}
