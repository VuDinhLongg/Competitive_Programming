#include <bits/stdc++.h>
using namespace std;

template<class X, class Y> bool maxi(X &x, const Y &y){ return x < y ? x = y, 1 : 0; }
template<class X, class Y> bool mini(X &x, const Y &y){ return x > y ? x = y, 1 : 0; }

#define el cout << '\n'
#define rep(i, n) fo(i, 0, n - 1)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define ret(x) return void(cout << (x) << '\n')
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define int long long
#define mxn 1'000'007

int n = 9;
char a[10][10];
vector<pair<int, int>> v;

int dist(pair<int, int> &a, pair<int, int> &b){
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool check(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c){
	int x1 = a.first - b.first;
	int y1 = a.second - b.second;
	int x2 = b.first - c.first;
	int y2 = b.second - c.second;
	return x1 * x2 + y1 * y2 == 0;
}

inline void solve(){
    fo(i, 1, n) fo(j, 1, n){
		cin >> a[i][j];
		if(a[i][j] == '#'){
			v.push_back({i, j});
		}
	}
	int res = 0;
	fo(i, 0, len(v) - 1) fo(j, i + 1, len(v) - 1) fo(k, j + 1, len(v) - 1) fo(p, k + 1, len(v) - 1){
		vector<pair<int, int>> t;
		t.push_back(v[i]);
		t.push_back(v[j]);
		t.push_back(v[k]);
		t.push_back(v[p]);
		do{
			int d = dist(t[0], t[1]), ok = 1;
			fo(i, 1, 3) if(dist(t[i], t[(i + 1) % 4]) != d){
				ok = 0; break;
			}
			if(ok){
				if(check(t[0], t[1], t[2])) ++res;
				break;
			}
		}while(next_permutation(all(t)));
	}
	cout << res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #define name "icpc"
    if(fopen(name".inp", "r")){
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    
    int o = 1; ///cin >> o;
    while(o --> 0) solve();
}