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
#define vi vector<int>

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

map<vi, int> f;
vi aim(7);

void edit1(vi &a){
	int tmp = a[1];
	swap(tmp, a[2]);
	swap(tmp, a[5]);
	swap(tmp, a[4]);
	swap(tmp, a[1]);
}

void edit2(vi &a){
	int tmp = a[2];
	swap(tmp, a[3]);
	swap(tmp, a[6]);
	swap(tmp, a[5]);
	swap(tmp, a[2]);
}

bool check(vi &x){
	for(int i=1; i<=6; i++){
		if(x[i] != aim[i]) return 0;
	}return 1;
}

int cal(vi &a){
	f.clear();
	queue<vi> q;
	q.push(a);
	f[a] = 0;
	while(!q.empty()){
		vi x = q.front(); q.pop();
		if(check(x)) return f[x];
		vi y = x, z = x;
		edit1(y); edit2(z);
		if(f[y] == 0){
			q.push(y);
			f[y] = f[x] + 1;
		}
		if(f[z] == 0){
			q.push(z);
			f[z] = f[x] + 1;
		}
	}return 0;
}

signed main(){
	LonggVuz();
	
	tc(){
		vi a(7);
		for(int i=1; i<=6; i++){
			cin >> a[i];
		}
		for(int i=1; i<=6; i++){
			cin >> aim[i];
		}cout << cal(a) << el;
	}
	
	End();
}