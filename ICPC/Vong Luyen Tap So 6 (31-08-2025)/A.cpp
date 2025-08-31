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



void LonggVuz(){
    string a; cin >> a;
    vec<int> cnt(500);
    int res = 0, cur = 0;
    fo(i, 0, len(a) - 1){
        if(a[i] == 'A'){
            if(cnt[23]) --cnt[23], --cur;
            else if(cnt[32]) --cnt[32], --cur;
            else{
                if(cnt[2]){
                    --cnt[2]; ++cnt[21];
                }else if(cnt[3]){
                    --cnt[3]; ++cnt[31];
                }else{
                    ++cnt[1]; ++cur;
                }
            }
        }else if(a[i] == 'B'){
            if(cnt[13]) --cnt[13], --cur;
            else if(cnt[31]) --cnt[31], --cur;
            else{
                if(cnt[1]){
                    --cnt[1]; ++cnt[12];
                }else if(cnt[3]){
                    --cnt[3]; ++cnt[32];
                }else{
                    ++cnt[2]; ++cur;
                }
            }
        }else{
            if(cnt[12]) --cnt[12], --cur;
            else if(cnt[21]) --cnt[21], --cur;
            else{
                if(cnt[1]){
                    --cnt[1]; ++cnt[13];
                }else if(cnt[2]){
                    --cnt[2]; ++cnt[23];
                }else{
                    ++cnt[3]; ++cur;
                }
            }
        }
        res = max(res, cur);
    }
    cout << res;
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
