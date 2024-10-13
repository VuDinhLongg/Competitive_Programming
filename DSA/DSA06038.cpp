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
#define int int32_t

const int mod = 1e9 + 7;
const int mxn = 1e5 + 7;

int n, a[mxn], f[4 * mxn];
map<int, int> mp;

void update(int id, int l, int r, int pos){
	if(l == r){
		++f[id]; return;
	}
	int m = (l + r) / 2;
	if(pos <= m) update(id * 2, l, m, pos);
	else update(id * 2 + 1, m + 1, r, pos);
	f[id] = f[id * 2] + f[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v){
	if(r < u or v < l) return 0;
	if(u <= l and r <= v) return f[id];
	int m = (l + r) / 2;
	return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
}

void LonggVuz(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		mp[a[i]] = 1;
	}
	int tmp = 1;
	for(auto &i : mp){
		mp[i.first] = tmp;
		++tmp;
	}
	int res = 0;
	vector<int> v;
	for(int i=1; i<=n; i++){
		if(a[i] % 2 == 0){
			v.pb(a[i]);
			res += get(1, 1, n, mp[a[i]] + 1, n);
		}else{
			for(int &i : v){
				update(1, 1, n, mp[i]);
			}v.clear();
		}
	}
	cout << res;
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}