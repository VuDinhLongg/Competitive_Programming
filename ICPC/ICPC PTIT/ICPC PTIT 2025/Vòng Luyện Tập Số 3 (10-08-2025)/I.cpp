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

const int mod = 1e9 + 7;
const int mxn = 1e5 + 7;

int a[15], f[15], used[15], res, del[15], aim;

inline int canh1(){
    return a[f[1]] + a[f[2]] + a[f[3]] + a[f[4]];
}

inline int canh2(){
    return a[f[1]] + a[f[5]] + a[f[6]] + a[f[7]];
}

inline int canh3(){
    return a[f[4]] + a[f[8]] + a[f[9]] + a[f[7]];
}

inline int canh4(){
    return a[f[10]] + a[f[2]] + a[f[5]] + a[f[11]];
}

inline int canh5(){
    return a[f[10]] + a[f[3]] + a[f[8]] + a[f[12]];
}

inline int canh6(){
    return a[f[11]] + a[f[6]] + a[f[9]] + a[f[12]];
}

inline void run(int pos){
    fo(i, 1, 12) if(!used[i]){
        f[pos] = i;
        if(pos == 1) del[i] = 1;
        else if(pos == 4 or pos == 7 or pos == 10 or pos == 11 or pos == 12){
            if(del[i]) continue;
        }
        used[i] = 1;
        if(pos == 12){
            if(aim == canh5() and aim == canh6()) ++res;
        }else{
            if(pos >= 11){
                if(aim == canh4()) run(pos + 1);
            }else if(pos >= 9){
                if(aim == canh3()) run(pos + 1);
            }else if(pos >= 7){
                if(aim == canh2()) run(pos + 1);
            }else if(pos >= 4){
                if(canh1() == aim) run(pos + 1);
            }else run(pos + 1);
        }
        used[i] = 0;
        f[pos] = 0;
    }
}

void LonggVuz(){
    fo(i, 1, 12) cin >> a[i];
    aim = 0;
    fo(i, 1, 12) aim += a[i];
    if(aim % 3) out(0);
    aim /= 3;
    sort(a+1, a+13);
    res = 0;
    run(1);
    cout << res / 2;
    fo(i, 1, 12) f[i] = used[i] = del[i] = 0;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed orz = 1; cin >> orz;
    while(orz --> 0){
        LonggVuz();
        if(orz) el;
    }
    
    cerr << "Execution Time: " << 0.001 * clock() << "s\n";
}
