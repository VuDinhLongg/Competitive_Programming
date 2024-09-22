// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Legendary Grandmaster
void End(){
    cerr << "=> Thời gian code chạy: ";
    cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define Sonic() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define ms(a, x) memset(a, x, sizeof(a))
#define bit(n, x) (n >> x & 1)
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int a[6], p[123][6], ok;

void hehe(){
	int t[6], id = 1;
	for(int i=1; i<=5; i++) t[i] = i;
	do{
		for(int i=1; i<=5; i++) p[id][i] = t[i];
		++id;
	}while(next_permutation(t+1, t+6));
}

void ql(int id, int i, int sum, char c){
	if(i == 6){
		if(sum == 23) ok = 1;
		return;
	}
	if(c == '+'){
		sum += a[p[id][i]];
	}else if(c == '-'){
		sum -= a[p[id][i]];
	}else sum *= a[p[id][i]];
	ql(id, i + 1, sum, '+'); if(ok) return;
	ql(id, i + 1, sum, '-'); if(ok) return;
	ql(id, i + 1, sum, '*'); if(ok) return;
}

void LonggVuz(){
	ok = 0;
	for(int i=1; i<=5; i++){
		cin >> a[i];
	}
	for(int i=1; i<=120; i++){
		ql(i, 1, 0, '+');
		if(ok) break;
	}
	if(ok){
		cout << "YES\n";
	}else cout << "NO\n";
}

signed main(){
	Sonic();
	
	hehe();
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}