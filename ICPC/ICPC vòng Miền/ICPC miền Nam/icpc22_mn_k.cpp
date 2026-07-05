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
#define len(x) (int)(x).size()
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 1'000'007

string name[] = {"", "White", "Silver", "Gray", "Black", "Red", "Maroon", "Yellow", "Olive", "Lime", "Green", "Aqua", "Teal", "Blue", "Navy", "Fuchsia", "Purple"};
int red[] = {0, 255, 192, 128, 0, 255, 128, 255, 128, 0, 0, 0, 0, 0, 0, 255, 128};
int green[] = {0, 255, 192, 128, 0, 0, 0, 255, 128, 255, 128, 255, 128, 0, 0, 0, 0};
int blue[] = {0, 255, 192, 128, 0, 0, 0, 0, 0, 0, 0, 255, 128, 255, 128, 255, 128};

inline void LonggVuz(){
	int r, g, b;
	while(cin >> r >> g >> b){
		if(r == -1) break;
		int res = 1e18, idx = 0;
		fo(i, 1, 16){
			int d = (red[i] - r) * (red[i] - r) + (green[i] - g) * (green[i] - g) + (blue[i] - b) * (blue[i] - b);
			if(mini(res, d)){
				idx = i;
			}
		}
		cout << name[idx], el;
	}
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(false) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
