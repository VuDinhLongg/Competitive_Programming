// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LonggVuz
#include <LonggVuz.h>
#else
#define debug(...)
#define print(...)
#endif

template<class X, class Y> bool maxi(X &a, const Y &b){ return b > a ? a = b, 1 : 0; }
template<class X, class Y> bool mini(X &a, const Y &b){ return b < a ? a = b, 1 : 0; }

#define el cout << '\n'
#define fup(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define fdn(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define out(x) return void(cout << (x))
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define dub double
#define int int64_t
#define ai2 array<int, 2>
#define ai3 array<int, 3>
#define ai4 array<int, 4>

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

int n, m, dp[4][101][101], dead[4][101][101];
int sx, sy, gx, gy;
char a[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void reset(){
    fo(i, 1, n) fo(j, 1, m) fo(k, 0, 3){
        dead[k][i][j] = 0;
    }
}

void tren(int i, int j, int x){
    --i;
    while(i >= 1 and a[i][j] == '.'){
        dead[x][i][j] = 1;
        --i;
    }
}

void phai(int i, int j, int x){
    ++j;
    while(j <= m and a[i][j] == '.'){
        dead[x][i][j] = 1;
        ++j;
    }
}

void duoi(int i, int j, int x){
    ++i;
    while(i <= n and a[i][j] == '.'){
        dead[x][i][j] = 1;
        ++i;
    }
}

void trai(int i, int j, int x){
    --j;
    while(j >= 1 and a[i][j] == '.'){
        dead[x][i][j] = 1;
        --j;
    }
}

inline void LonggVuz(){
    reset();
    cin >> n >> m;
    fo(i, 1, n) fo(j, 1, m){
        cin >> a[i][j];
        if(a[i][j] == 'S'){
            sx = i;
            sy = j;
            a[i][j] = '.';
        }else if(a[i][j] == 'G'){
            gx = i;
            gy = j;
            a[i][j] = '.';
        }
    }
    fo(i, 1, n) fo(j, 1, m){
        if(a[i][j] == '^'){
            fo(k, 0, 3) dead[k][i][j] = 1;
            tren(i, j, 0);
            phai(i, j, 1);
            duoi(i, j, 2);
            trai(i, j, 3);
        }else if(a[i][j] == '>'){
            fo(k, 0, 3) dead[k][i][j] = 1;
            phai(i, j, 0);
            duoi(i, j, 1);
            trai(i, j, 2);
            tren(i, j, 3);
        }else if(a[i][j] == 'v'){
            fo(k, 0, 3) dead[k][i][j] = 1;
            duoi(i, j, 0);
            trai(i, j, 1);
            tren(i, j, 2);
            phai(i, j, 3);
        }else if(a[i][j] == '<'){
            fo(k, 0, 3) dead[k][i][j] = 1;
            trai(i, j, 0);
            tren(i, j, 1);
            phai(i, j, 2);
            duoi(i, j, 3);
        }
    }
    fo(i, 1, n) fo(j, 1, m) fo(k, 0, 3){
        dp[k][i][j] = oo;
    }
    queue<ai3> q;
    q.push({0, sx, sy});
    dp[0][sx][sy] = 0;
    while(!q.empty()){
        auto [tt, i, j] = q.front(); q.pop();
        if(i == gx and j == gy) break;
        int ntt = (tt + 1) % 4;
        fo(k, 0, 3){
            int ii = i + dx[k];
            int jj = j + dy[k];
            if(1 <= ii and ii <= n and 1 <= jj and jj <= m){
                if(a[ii][jj] != '#' and !dead[ntt][ii][jj] and mini(dp[ntt][ii][jj], dp[tt][i][j] + 1)){
                    q.push({ntt, ii, jj});
                }
            }
        }
    }
    int res = oo;
    fo(k, 0, 3) mini(res, dp[k][gx][gy]);
    if(res < oo) cout << res, el;
    else cout << "impossible\n";
}

signed main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    
    signed hehe = 1; if(1) cin >> hehe;
    for(signed hihi = 1; hihi <= hehe; ++hihi){
        print(hihi);
        LonggVuz();
    }
    
    cerr << "Execution Time: " << clock() << "ms\n";
}
