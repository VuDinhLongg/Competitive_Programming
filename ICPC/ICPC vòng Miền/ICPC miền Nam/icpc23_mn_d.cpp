// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <LonggVuz.h>
#else
#define debug(...)
#endif

#define el cout << '\n'
#define inc(i, a, b, c) for(int32_t i=a; i<=b; i+=c)
#define dec(i, a, b, c) for(int32_t i=a; i>=b; i-=c)
#define fo(i, a, b) for(int32_t i=a; i<=b; i++)
#define fd(i, a, b) for(int32_t i=a; i>=b; i--)
#define out(x) return void(cout << (x))
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define vec vector
#define pub push_back
#define pob pop_back
#define dub double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

template <typename T>
using maxpq = priority_queue<T>;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

#define pii pair<int, int>
#define pip pair<int, pii>
#define ppi pair<pii, int>
#define fi first
#define se second

int n, g, a[505][505], dp[505][505], vis[505][505];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void run(int i, int j, int m){
    vis[i][j] = 1;
    if(i == n and j == n) return;
    fo(k, 0, 3){
        int ii = i + dx[k];
        int jj = j + dy[k];
        if(1 <= ii and ii <= n and 1 <= jj and jj <= n and !vis[ii][jj] and a[ii][jj] >= m){
            run(ii, jj, m);
        }
    }
}

bool check(int m){
    fo(i, 1, n) fo(j, 1, n) vis[i][j] = 0;
    run(1, 1, m);
    return vis[n][n];
}

void solve1(){
    cin >> n >> g;
    fo(i, 1, n) fo(j, 1, n){
        cin >> a[i][j];
        dp[i][j] = oo;
    }
    dp[1][1] = a[1][1] < g;
    minpq<pip> q;
    q.push({dp[1][1], {1, 1}});
    while(!q.empty()){
        auto [cur, p] = q.top(); q.pop();
        auto [i, j] = p;
        if(cur > dp[i][j]) continue;
        if(i == n and j == n) break;
        fo(k, 0, 3){
            int ii = i + dx[k];
            int jj = j + dy[k];
            if(1 <= ii and ii <= n and 1 <= jj and jj <= n){
                int c = a[ii][jj] < g;
                if(dp[i][j] + c < dp[ii][jj]){
                    dp[ii][jj] = dp[i][j] + c;
                    q.push({dp[ii][jj], {ii, jj}});
                }
            }
        }
    }
    cout << dp[n][n];
}

void solve2(){
    cin >> n;
    fo(i, 1, n) fo(j, 1, n){
        cin >> a[i][j];
    }
    int l = 0, r = 1e4 + 1;
    while(r - l > 1){
        int m = l + r >> 1;
        if(check(m)) l = m;
        else r = m;
    }
    cout << l;
}

inline void LonggVuz(){
    int type; cin >> type;
    if(type == 1) solve1();
    else solve2();
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
