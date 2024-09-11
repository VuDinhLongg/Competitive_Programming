// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Noob C++
void End(){
    cerr << "=> Thời gian code chạy: ";
    cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define LonggVuz() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define ms(x) memset(x, 0, sizeof(x))
#define tc() int TC; cin >> TC; while(TC--)
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define str string
#define int int32_t
#define ld long double
#define psi pair<str, int>

const int mod = 1e9 + 7;
const int oo = 1e8 + 7;
const int maxn = 1e4 + 7;

int n;
str s, t;
set<str> a;

int cal(){
	queue<psi> q;
	q.push({s, 1});
	while(!q.empty()){
		psi x = q.front(); q.pop();
		if(x.fi == t) return x.se;
		for(int i=0; i<len(x.fi); i++){
			str tmp = x.fi;
			for(char c='A'; c<='Z'; c++){
				tmp[i] = c;
				if(a.count(tmp)){
					q.push({tmp, x.se + 1});
					a.erase(tmp);
				}
			}
		}
	}return 0;
}

signed main(){
	LonggVuz();
	
	tc(){
		cin >> n >> s >> t;
		for(int i=1; i<=n; i++){
			str xau; cin >> xau;
			a.insert(xau);
		}cout << cal() << el;
	}
	
	End();
}