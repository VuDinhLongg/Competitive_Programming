// LonggVuz
#include<bits/stdc++.h>
using namespace std;
// Think twice, code once ^.^
void End(){
    cerr << "=> Smoothly Finished! Time taken: ";
    cerr << (0.001 * clock()) << "s" << string(25, '\t');
}
#define Sonic() cin.tie(0) -> sync_with_stdio(0)
#define out(x) return cout << x << el, void()
#define fix(x) fixed << setprecision(x)
#define all(x) begin(x), end(x)
#define len(x) (int)x.size()
#define ms(a, x) memset(a, x, sizeof(a))
#define bit(n, x) (n >> x & 1)
#define pb push_back
#define is insert
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e5 + 7;

int n, q;
string a, s[mxn * 4];

bool dx(string str){
	int l = 0, r = len(str) - 1;
	while(l < r){
		if(str[l] != str[r]) return 0;
		++l; --r;
	}return 1;
}

void build(int id, int l, int r){
	if(l == r){
		s[id] = string(1, a[l]);
		return;
	}int m = (l + r) / 2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	s[id] = s[id * 2] + s[id * 2 + 1];
}

void update(int id, int l, int r, int pos, char c){
	if(l == r){
		s[id] = string(1, c);
		return;
	}int m = (l + r) / 2;
	if(pos <= m) update(id * 2, l, m, pos, c);
	else update(id * 2 + 1, m + 1, r, pos, c);
	s[id] = s[id * 2] + s[id * 2 + 1];
}

string get(int id, int l, int r, int u, int v){
	if(r < u or v < l) return "";
	if(u <= l and r <= v) return s[id];
	int m = (l + r) / 2;
	return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
}
// AC in 1.43s
void LonggVuz(){
	cin >> a >> q;
	n = len(a);
	a = "@" + a;
	build(1, 1, n);
	while(q--){
		char c; cin >> c;
		if(c == 'q'){
			int l, r; cin >> l >> r;
			string str = get(1, 1, n, l, r);
			if(dx(str)){
				cout << "YES\n";
			}else cout << "NO\n";
		}else{
			int pos; char x; cin >> pos >> x;
			update(1, 1, n, pos, x);
		}
	}
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}

/*
// LonggVuz
#include<bits/stdc++.h>
using namespace std;
// ☞ Think twice, code once ☜
void End(){
    cerr << "=> Smoothly Finished! Time taken: ";
    cerr << (0.001 * clock()) << "s" << string(25, '\t');
}
#define Sonic() cin.tie(0) -> sync_with_stdio(0)
#define out(x) return cout << x, void()
#define fix(x) fixed << setprecision(x)
#define all(x) begin(x), end(x)
#define len(x) (int)x.size()
#define ms(a, x) memset(a, x, sizeof(a))
#define bit(n, x) (n >> x & 1)
#define pb push_back
#define is insert
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

int n, q;
string a;
// AC in 0.40s
void LonggVuz(){
	cin >> a >> q;
	n = len(a);
	a = "@" + a;
	while(q--){
		char c; cin >> c;
		if(c == 'q'){
			int l, r; cin >> l >> r;
			bool ok = 1;
			while(l < r){
				if(a[l] != a[r]){
					ok = 0; break;
				}
				++l; --r;
			}
			if(ok) cout << "YES\n";
			else cout << "NO\n";
		}else{
			int pos; char x; cin >> pos >> x;
			a[pos] = x;
		}
	}
}

signed main(){
	Sonic();
	
	int TC = 1; //cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
*/