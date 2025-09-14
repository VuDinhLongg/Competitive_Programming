// LonggVuz
#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<LonggVuz.h>
#else
#define debug(...)
#endif

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
#define float long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;
const float eps = 1e-9;

float dis(float a, float b, float c, float d){
    return sqrtl((a - c) * (a - c) + (b - d) * (b - d));
}

void LonggVuz(){
    cout << fixed << setprecision(6);
    float a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    float canh1 = dis(a, b, c, d);
    float canh2 = dis(a, b, e, f);
    float canh3 = dis(c, d, e, f);
    float p = canh1 + canh2 + canh3; p /= 2;
    float s = sqrtl(p * (p - canh1) * (p - canh2) * (p - canh3));
    debug(canh1, canh2, canh3);
    if(abs(canh1 * canh2 - s * 2.0) <= eps) out("Yes");
    if(abs(canh1 * canh3 - s * 2.0) <= eps) out("Yes");
    if(abs(canh3 * canh2 - s * 2.0) <= eps) out("Yes");
    cout << "No";
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; if(false) cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
