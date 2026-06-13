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

const double pi = acosl(-1.0L);
const double eps = 1e-9L;

struct Point{
	int x, y;
	Point(){}
	Point(int x, int y) : x(x), y(y) {}
};

Point operator + (const Point &a, const Point &b){ return Point(a.x + b.x, a.y + b.y); }
Point operator - (const Point &a, const Point &b){ return Point(a.x - b.x, a.y - b.y); }
int cross(const Point &a, const Point &b){ return a.x * b.y - a.y * b.x; }
int prod(const Point &a, const Point &b){ return a.x * b.x + a.y * b.y; }
double dist(const Point &a, const Point &b){ return sqrtl(prod(a - b, a - b)); }
int ccw(const Point &a, const Point &b, const Point &c){
	Point ab = b - a, ac = c - a;
	int tmp = cross(ab, ac);
	if(tmp < 0) return -1; // re phai
	if(tmp > 0) return 1; // re trai
	return 0; // di thang
}

Point a[4], b[4], c[4];

bool check(){
	int dx = a[0].x - b[0].x;
	int dy = a[0].y - b[0].y;
	fo(i, 1, 3){
		int fx = a[i].x - b[i].x;
		int fy = a[i].y - b[i].y;
		if(dx != fx or dy != fy) return 0;
	}
	return 1;
}

inline void LonggVuz(){
    rep(i, 4) cin >> a[i].x >> a[i].y;
    int t; cin >> t;
    int res = 0;
    while(t--){
    	rep(i, 4) cin >> c[i].x >> c[i].y;
    	vector<int> idx;
    	rep(i, 4) idx.push_back(i);
    	do{
    		rep(i, 4) b[i] = c[idx[i]];
    		if(check()){
    			++res;
    			break;
    		}
    	}while(next_permutation(all(idx)));
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
