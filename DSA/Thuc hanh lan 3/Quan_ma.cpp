// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Legendary Grandmaster
void End(){
    cerr << "=> Smoothly Finished! Time taken: ";
    cerr << (0.001 * clock()) << "s" << string(25, '\t');
}
#define Sonic() cin.tie(NULL) -> sync_with_stdio(false);
#define fix(x) fixed << setprecision(x)
#define all(x) begin(x), end(x)
#define len(x) (int)x.size()
#define gel(x) getline(cin >> ws, x)
#define ms(a, x) memset(a, x, sizeof(a))
#define bit(n, x) (n >> x & 1)
#define pb push_back
#define is insert
#define el '\n'
#define ld long double
#define int int64_t
#define pii pair<int, int>
#define fi first
#define se second

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int f[10][10];

int bfs(int s1, int s2, int e1, int e2){
    queue<pii> q;
    q.push({s1, s2});
    while(!q.empty()){
        pii x = q.front(); q.pop();
        int i = x.fi, j = x.se;
        if(i == e1 and j == e2) return f[i][j];
        for(int k=0; k<8; k++){
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if(1 <= i1 and i1 <= 8 and 1 <= j1 and j1 <= 8 and f[i1][j1] == 0){
                f[i1][j1] = f[i][j] + 1;
                q.push({i1, j1});
            }
        }
    }return oo;
}

void LonggVuz(){
    ms(f, 0);
    string a, b; cin >> a >> b;
    int s1 = a[0] - 'a' + 1;
    int s2 = a[1] - '0';
    int e1 = b[0] - 'a' + 1;
    int e2 = b[1] - '0';
    cout << bfs(s1, s2, e1, e2) << el;
}

signed main(){
    Sonic();
    
    int TC = 1; cin >> TC;
    while(TC--) LonggVuz();
    
    End();
}
