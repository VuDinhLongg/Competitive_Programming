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

void solve(int a[], int n, int k){
	int x[k+5], ok = 0;
	for(int i=1; i<=k; i++) x[i] = a[i];
    for(int i=k; i>=1; i--){
        if(a[i] < n - k + i){
            ++a[i];
            for(int j=i+1; j<=k; j++){
                a[j] = a[j-1] + 1;
            }ok = 1; break;
        }
    }if(!ok) return cout << k << el, void();
    int res = 0;
    for(int i=1; i<=k; i++){
    	bool tm = 1;
    	for(int j=1; j<=k; j++){
    		if(x[i] == a[j]){
    			tm = 0; break;
    		}
    	}res += tm;
    }cout << res << el;
}

signed main(){
	LonggVuz();
	
	tc(){
		int n, k; cin >> n >> k;
		int a[k+5];
		for(int i=1; i<=k; i++){
			cin >> a[i];
		}solve(a, n, k);
	}
	
	End();
}