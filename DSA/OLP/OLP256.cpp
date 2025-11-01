// LonggVuz
#include <bits/stdc++.h>
using namespace std;

#ifdef LonggVuz
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

vec<int> v;
void pre(){
	queue<int> q;
	map<int, int> used;
	fo(i, 0, 9){
		q.push(i);
		used[i] = 1;
	}
	while(!q.empty()){
		int x = q.front(); q.pop();
		if(x > 1e9) return;
		v.pub(x);
		int d = x % 10;
		fo(i, d + 1, 9){
			if(!used.count(x * 10 + i)){
				q.push(x * 10 + i);
				used[x * 10 + i] = 1;
			}
		}
	}
	sort(all(v));
}

inline void LonggVuz(){
	int n; cin >> n;
	int l = 0, r = len(v);
	while(r - l > 1){
		int m = l + r >> 1;
		if(v[m] <= n) l = m;
		else r = m;
	}
	cout << v[l];
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	pre();
	signed orz = 1; if(1) cin >> orz;
	while(orz --> 0){
		LonggVuz();
		if(orz) el;
	}

	cerr << "Execution Time: " << clock() << "ms\n";
}
