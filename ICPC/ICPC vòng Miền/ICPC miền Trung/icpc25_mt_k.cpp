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

vector<int> gt = {1, 1, 2, 6, 24, 120, 720};

int get(int i){
    cout << "? " << i << endl;
    int g; cin >> g;
    return g;
}

bool check(vector<int> &v, int i){
    for(int &x : v) if(x == i) return 1;
    return 0;
}

inline void LonggVuz(){
    int n; cin >> n;
    vector<int> cur;
    fo(i, 1, n * 6) cur.push_back(i);
    vector<int> res;
    fo(pos, 1, 5){
        vector<int> cnt(7, 0);
        vector<vector<int>> val(7);
        for(int &i : cur) if(i % 6 == pos){
            int g = get(i);
            val[g].push_back(i + 1);
        }
        fo(i, 1, 6) if(!check(res, i) and val[i].size() < gt[6 - pos]){
            res.push_back(i);
            cur = val[i];
            break;
        }
    }
    fo(i, 1, 6) if(!check(res, i)){
        res.push_back(i);
        break;
    }
    cout << "! ";
    for(int &i : res) cout << i << ' '; cout << endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(1) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}