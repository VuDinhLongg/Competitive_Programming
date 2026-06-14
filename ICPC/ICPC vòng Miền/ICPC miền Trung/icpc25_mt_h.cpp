/*======================
   Author : @LonggVuz
======================*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define orz(...) 2005
#endif

#define el cout << '\n'
#define all(x) begin(x), end(x)
#define fix(x) fixed << setprecision(x)
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 1'000'007

int n, t, d1, d2, d3, cnt[5], sum[5], used[16];
vector<vector<int>> res;
vector<int> v;

int stt(int pos){
    if(d1 < pos and pos < d2) return 1;
    if(d2 < pos and pos < d3) return 2;
    return 3;
}

void run(int pos){
    if(pos > n){
        res.push_back(v);
        return;
    }
    fo(i, 1, n) if(used[i] == 0){
        used[i] = 1;
        v.push_back(i);
        if(pos == d1){
            cnt[1] += 1;
            cnt[3] += 1;
            sum[1] += i;
            sum[3] += i;
        }else if(pos == d2){
            cnt[1] += 1;
            cnt[2] += 1;
            sum[1] += i;
            sum[2] += i;
        }else if(pos == d3){
            cnt[2] += 1;
            cnt[3] += 1;
            sum[2] += i;
            sum[3] += i;
        }else{
            int x = stt(pos);
            cnt[x] += 1;
            sum[x] += i;
        }
        bool ok = 1;
        if(cnt[1] == d2 - d1 + 1){
            if(sum[1] != t) ok = 0;
        }
        if(cnt[2] == d2 - d1 + 1){
            if(sum[2] != t) ok = 0;
        }
        if(cnt[3] == d2 - d1 + 1){
            if(sum[3] != t) ok = 0;
        }
        if(ok) run(pos + 1);
        used[i] = 0;
        v.pop_back();
        if(pos == d1){
            cnt[1] -= 1;
            cnt[3] -= 1;
            sum[1] -= i;
            sum[3] -= i;
        }else if(pos == d2){
            cnt[1] -= 1;
            cnt[2] -= 1;
            sum[1] -= i;
            sum[2] -= i;
        }else if(pos == d3){
            cnt[2] -= 1;
            cnt[3] -= 1;
            sum[2] -= i;
            sum[3] -= i;
        }else{
            int x = stt(pos);
            cnt[x] -= 1;
            sum[x] -= i;
        }
    }
}

inline void LonggVuz(){
    cin >> n >> t;
    if(n == 3){
        d1 = 1; d2 = 2; d3 = 3;
    }else if(n == 6){
        d1 = 1; d2 = 3; d3 = 5;
    }else if(n == 9){
        d1 = 1; d2 = 4; d3 = 7;
    }else{
        d1 = 1; d2 = 5; d3 = 9;
    }
    res.clear();
    v.clear();
    memset(cnt, 0, sizeof cnt);
    memset(sum, 0, sizeof sum);
    memset(used, 0, sizeof used);
    run(1);
    if(res.size() == 0) out(-1);
    sort(all(res));
    for(auto &ve : res){
        for(int &i : ve) cout << i << ' '; el;
    }
    cout << res.size();
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}