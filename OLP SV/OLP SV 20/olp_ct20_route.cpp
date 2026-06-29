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
#define ai3 array<int, 3>
#define ai4 array<int, 4>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, a[1005][1005], f[6][1005][1005], pre[6][1005][1005];

int get(int n, int x){
	if(n == 0) return 1e9;
	int r = 0;
	while(n % x == 0){
		++r;
		n /= x;
	}
	return r;
}

void prepare(int x){
	f[x][1][1] = get(a[1][1], x);
	fo(i, 2, n) f[x][i][1] = f[x][i - 1][1] + get(a[i][1], x), pre[x][i][1] = 1;
	fo(i, 2, m) f[x][1][i] = f[x][1][i - 1] + get(a[1][i], x), pre[x][1][i] = 2;
	fo(i, 2, n) fo(j, 2, m){
		int g = get(a[i][j], x);
		if(f[x][i - 1][j] < f[x][i][j - 1]){
			f[x][i][j] = f[x][i - 1][j] + g;
			pre[x][i][j] = 1;
		}else{
			f[x][i][j] = f[x][i][j - 1] + g;
			pre[x][i][j] = 2;
		}
	}
}

string trace_zero(){
	string s = "";
	fd(i, n, 1) fo(j, 1, m) if(a[i][j] == 0){
		if(i == n or j == 1){
			return string(n - 1, 'D') + string(m - 1, 'L');
		}
		if(s.empty()){
			rep(_, i - 1) s.push_back('D');
			rep(_, j - 1) s.push_back('L');
			rep(_, n - i) s.push_back('D');
			rep(_, m - j) s.push_back('L');
		}
	}
	return s;
}

string trace(int pre[1005][1005]){
	int i = n, j = m;
	string s = "";
	while(i > 1 and j > 1){
		if(pre[i][j] == 1){
			s.push_back('D');
			--i;
		}else{
			s.push_back('L');
			--j;
		}
	}
	while(i > 1) s.push_back('D'), --i;
	while(j > 1) s.push_back('L'), --j;
	reverse(all(s));
	return s;
}

inline void LonggVuz(){
    cin >> n >> m;
    bool zero = 0;
    fo(i, 1, n) fo(j, 1, m){
    	cin >> a[i][j];
    	if(a[i][j] == 0) zero = 1;
    }
    prepare(2);
    prepare(5);
    if(zero){
    	if(min(f[2][n][m], f[5][n][m]) > 1){
    		cout << 1, el;
    		cout << trace_zero();
    	}else if(min(f[2][n][m], f[5][n][m]) == 1){
    		cout << 1, el;
    		string s0 = trace_zero();
    		string s2 = "Z";
    		string s5 = "Z";
    		if(f[2][n][m] == 1) s2 = trace(pre[2]);
    		if(f[5][n][m] == 1) s5 = trace(pre[5]);
    		cout << min({s0, s2, s5});
    	}else{
    		if(f[2][n][m] < f[5][n][m]){
	    		cout << f[2][n][m], el;
	    		cout << trace(pre[2]);
	    	}else if(f[2][n][m] > f[5][n][m]){
	    		cout << f[5][n][m], el;
	    		cout << trace(pre[5]);
	    	}else{
	    		cout << f[2][n][m], el;
	    		string s2 = trace(pre[2]);
	    		string s5 = trace(pre[5]);
	    		cout << min(s2, s5);
	    	}
    	}
    }else{
    	if(f[2][n][m] < f[5][n][m]){
    		cout << f[2][n][m], el;
    		cout << trace(pre[2]);
    	}else if(f[2][n][m] > f[5][n][m]){
    		cout << f[5][n][m], el;
    		cout << trace(pre[5]);
    	}else{
	    	cout << f[2][n][m], el;
    		string s2 = trace(pre[2]);
    		string s5 = trace(pre[5]);
    		cout << min(s2, s5);
    	}
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    signed o = 1; if(false) cin >> o;
    rep(i, o) orz(i), LonggVuz();
    
    cerr << "[exec time = `" << clock() << "ms`]";
}
