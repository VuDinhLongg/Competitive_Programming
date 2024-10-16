// https://luyencode.net/problem/k-number
// LonggVu.
#include<bits/stdc++.h>
using namespace std;
// Noob C++
void End(){
    cerr << "=> Thời gian code chạy: ";
    cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define LonggVu() ios_base::sync_with_stdio(false); cin.tie(NULL);
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
#define int long long
#define db double

void solve(int a[], int n){
	for(int k=1; k<=n; k++){
		int dem[1005] = {0};
		bool tm[1005] = {0};
		for(int i=1; i<=k; i++){
			++dem[a[i]];
			tm[a[i]] = 1;
		}
		for(int i=k+1; i<=n; i++){
			--dem[a[i-k]];
			++dem[a[i]];
			if(dem[a[i-k]] == 0) tm[a[i-k]] = 0;
		}bool ok = 0;
		for(int i=1; i<=n; i++){
			if(tm[i]){
				cout << i << ' ';
				ok = 1; break;
			}
		}if(!ok) cout << "-1 ";
	}cout << el;
}

signed main(){
	LonggVu();
	
	tc(){
		int n; cin >> n;
		int a[n+5];
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}solve(a, n);
	}
	
	End();
}
