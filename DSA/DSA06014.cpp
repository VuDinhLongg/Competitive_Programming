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

bool nt[maxn];
void sang(){
	nt[0] = nt[1] = 1;
	for(int i=2; i<=1e3; i++)
		if(!nt[i])
			for(int j=i*i; j<=1e6; j+=i) nt[j] = 1;
}

signed main(){
	LonggVuz();
	
	sang();
	tc(){
		int n; cin >> n;
		if(!nt[n - 2]){
			cout << "2 " << n - 2 << el;
		}else{
			bool ok = 0;
			for(int i=3; i<=n/2; i+=2){
				if(!nt[i] && !nt[n-i]){
					cout << i << ' ' << n - i << el;
					ok = 1; break;
				}
			}if(!ok) cout << "-1\n";
		}
	}
	
	End();
}