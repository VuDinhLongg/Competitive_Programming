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
#define pb push_back
#define po pop_back
#define int int64_t

const int mod = 998244353;
const int oo = 1e18 + 8;
const int mxn = 2e5 + 9;

/*
Main Idea:
1, Sắp xếp mảng tăng dần, sau đó ách mảng thành từng cấp số cộng có công sai là k.
    Ví dụ: test 2 4 7 9, ta sẽ tách thành [2, 4] và [7, 9] để xử lý riêng.
2, Với dãy [2, 4], ta sẽ chỉ có 1 cách tạo ra dãy "xấu" là dãy [2, 4].
    Xét tiếp đến dãy [7, 9], ta vẫn chỉ có 1 cách tạo ra dãy xấu.
    Tuy nhiên, khi ta ghép với kết quả đang có là 1 (của dãy [2, 4]),
    ta sẽ có các cách ghép như sau:
        +, Tính tổng số lượng phần tử ĐÃ xử lý (ở đây là 2) => có 4 trạng thái mask
            tức là có thể ghép ra [7, 9], [2, 7, 9], [4, 7, 9], [2, 4, 7, 9].
        +, Tính tổng số lượng phần tử ĐANG xử lý (ở đây là 2) => 2 trạng thái ko tạo ra dãy xấu
            tức là [7], [9] (bỏ đi số mask "xấu" và mask rỗng)
            tức là có thể ghép ra [2, 4, 7], [2, 4, 9].
3, Chốt lại, ta sẽ có 7 masks xấu là [2, 4], [7, 9], [2, 7, 9], [4, 7, 9], [2, 4, 7, 9], [2, 4, 7], [2, 4, 9]
    Sau đó, lấy tổng 2^n - 1 mask trừ đi số mask xấu là ra đáp án.
*/

int n, k, a[mxn], h[mxn];

void pre(){
    h[0] = 1;
    fo(i, 1, 2e5) h[i] = h[i - 1] * 2 % mod;
}

void LonggVuz(){
    cin >> n >> k;
    fo(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    map<int, int> cnt, used;
    fo(i, 1, n) ++cnt[a[i]];
    int res = 0, cur = 0, i = 1;
    while(i <= n){
        if(used[a[i]]){
            ++i;
            continue;
        }
        vec<int> v, len;
        int x = a[i];
        while(cnt.count(x)){
            v.pb(x);
            used[x] = 1;
            if(len.empty()) len.pb(cnt[x]);
            else len.pb(len.back() + cnt[x]);
            x += k;
        }
        int sum = 0, m = len(v);
        vec<int> f(m), g(m), pf(m);
        f[0] = g[0] = pf[0] = 0;
        fo(j, 1, m - 1){
            int c1 = cnt[v[j]];
            int c2 = cnt[v[j - 1]];
            int w1 = h[c1] - 1;
            int w2 = h[c2] - 1;
            f[j] = w1 * w2 % mod * h[len[j] - c1 - c2] % mod;
            if(j >= 2) g[j] = (w1 * pf[j - 2]) % mod;
            pf[j] = (pf[j - 1] + g[j] + f[j]) % mod;
            sum = (sum + f[j] + g[j]) % mod;
            // cout << v[j] << ' ' << f[j] << ' ' << g[j] << ' ' << pf[j] << '\n';
        }
        res = (res + res * (h[len.back()] - 1 - pf[m - 1] + mod) % mod) % mod;
        res = (res + (pf[m - 1] * h[cur]) % mod) % mod;
        cur += len.back();
        ++i;
        // for(int &x : v) cout << x << ' '; cout << sum, el;
    }
    res = (h[n] - 1 - res + mod * 2) % mod;
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    pre();
    signed orz = 1; cin >> orz;
    while(orz--){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
