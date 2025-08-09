/*
Sân thi đấu robocon có kích thước vuông gồm NxN ô bàn cờ. Tại mỗi ô có đặt một số lượng hộp quà nhất định. Thời gian di chuyển giữa 2 ô liền nhau (trái, phải, trên, dưới) là T đơn vị. Ban đầu, robot ở vị trí xuất phát (1, 1) và cần di chuyển tới vị trí đích (N, N).
Luật chơi quy định của BTC là cứ mỗi khi robot di chuyển đủ 3 bước, robot sẽ phải dừng lại ở vị trí hiện tại để thu lượm đủ tất cả các hộp quà hiện có (kể cả trường hợp vị trí này là ô kết thúc). Để lấy 1 hộp quà, robot mất 1 đơn vị thời gian.
Nhiệm vụ của các bạn là hãy sắp xếp chiến thuật di chuyển robot tối ưu, sao cho có thể đi được từ ô xuất phát tới đích nhanh nhất có thể? Có nhiều ô có rất nhiều hộp quà, vì vậy, bạn không nên dừng lại ở những vị trí này để lấy quà, nếu không sẽ mất nhiều thời gian.
Input:
Dòng đầu tiên chứa hai số nguyên N và T (3 <= N <= 100, 0 <= T <= 10^6).
N dòng tiếp theo, mỗi dòng gồm N số nguyên mô tả bảng A[i][j] (1 <= A[i][j] <= 10^5).
Output: 
In ra thời gian ngắn nhất để có thể hoàn thành hành trình di chuyển của robot.
Giới hạn: 30% test có N <= 30.
============================================================================
Input 1:            Output 1:
4 2                 36
31 52 10 80
38 95 60 16
41 10 10 18
25 17 13 80
Input 2:            Output 2:
4 3                 33
50 50 50 50
50 50 1 50
1 50 50 50
50 50 1 50
============================================================================
*/
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

#define pi pair<int, int>
#define pe pair<pi, pi>
#define fi first
#define se second

int n, t, a[101][101], dp[101][101][3];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void LonggVuz(){
    cin >> n >> t;
    fo(i, 1, n) fo(j, 1, n) cin >> a[i][j];
    fo(i, 1, n) fo(j, 1, n) fo(k, 0, 2) dp[i][j][k] = oo;
    dp[1][1][0] = 0;
    priority_queue<pe, vec<pe>, greater<pe>> q;
    q.push({{dp[1][1][0], 0}, {1, 1}});
    while(!q.empty()){
        auto [top1, top2] = q.top(); q.pop();
        auto [cur, k] = top1;
        auto [i, j] = top2;
        if(cur > dp[i][j][k]) continue;
        fo(id, 0, 3){
            int ii = i + dx[id];
            int jj = j + dy[id];
            if(1 <= ii and ii <= n and 1 <= jj and jj <= n){
                int kk = (k + 1) % 3;
                int cost = t;
                if(kk == 0) cost += a[ii][jj];
                if(dp[i][j][k] + cost < dp[ii][jj][kk]){
                    dp[ii][jj][kk] = dp[i][j][k] + cost;
                    q.push({{dp[ii][jj][kk], kk}, {ii, jj}});
                }
            }
        }
    }
    int res = oo;
    fo(k, 0, 2) res = min(res, dp[n][n][k]);
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
