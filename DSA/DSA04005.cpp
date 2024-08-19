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
#define ms(a, x) memset(a, x, sizeof(a))
#define tc() int TC; cin >> TC; while(TC--)
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define str string
#define int intmax_t
#define db double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

int l[100];
void hehe(){
	l[1] = 1; l[2] = 1;
	for(int i=3; i<=93; i++){
		l[i] = l[i-2] + l[i-1];
	}
}

signed main(){
	LonggVuz();
	
	hehe();
	tc(){
		int n, k; cin >> n >> k;
		int pos = n;
		while(pos > 2){
			if(k <= l[pos-2]) pos -= 2;
			else{
				k -= l[pos-2];
				--pos;
			}
		}if(pos == 1) cout << "A\n";
		else cout << "B\n";
	}
	
	End();
}