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
#define int int64_t
#define ld long double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

void solve(int a[], int n){
	priority_queue<int, vector<int>, greater<int>> x, y, z;
	int sum = 0;
	for(int i=1; i<=n; i++){
		sum += a[i];
		if(a[i] % 3 == 0) x.push(a[i]);
		else if(a[i] % 3 == 1) y.push(a[i]);
		else z.push(a[i]);
	}if(sum % 3 == 0){
		str res = "";
		for(int i=1; i<=n; i++) res.pb(a[i] + '0');
		sort(all(res), greater<char>());
		cout << res << el;
	}else if(sum % 3 == 1){
		if(len(y) >= 1){
			y.pop();
			str res = "";
			while(!x.empty()){
				res.pb(x.top() + '0');
				x.pop();
			}
			while(!y.empty()){
				res.pb(y.top() + '0');
				y.pop();
			}
			while(!z.empty()){
				res.pb(z.top() + '0');
				z.pop();
			}sort(all(res), greater<char>());
			if(len(res)) cout << res << el;
			else cout << "-1\n";
		}else if(len(z) >= 2){
			z.pop(); z.pop();
			str res = "";
			while(!x.empty()){
				res.pb(x.top() + '0');
				x.pop();
			}
			while(!z.empty()){
				res.pb(z.top() + '0');
				z.pop();
			}sort(all(res), greater<char>());
			if(len(res)) cout << res << el;
			else cout << "-1\n";
		}else cout << "-1\n";
	}else{
		if(len(z) >= 1){
			z.pop();
			str res = "";
			while(!x.empty()){
				res.pb(x.top() + '0');
				x.pop();
			}
			while(!y.empty()){
				res.pb(y.top() + '0');
				y.pop();
			}
			while(!z.empty()){
				res.pb(z.top() + '0');
				z.pop();
			}sort(all(res), greater<char>());
			if(len(res)) cout << res << el;
			else cout << "-1\n";
		}else if(len(y) >= 2){
			y.pop(); y.pop();
			str res = "";
			while(!x.empty()){
				res.pb(x.top() + '0');
				x.pop();
			}
			while(!y.empty()){
				res.pb(y.top() + '0');
				y.pop();
			}sort(all(res), greater<char>());
			if(len(res)) cout << res << el;
			else cout << "-1\n";
		}else cout << "-1\n";
	}
}

signed main(){
	LonggVuz();
	
	tc(){
		int n; cin >> n;
		int a[n+5];
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}solve(a, n);
	}
	
	End();
}