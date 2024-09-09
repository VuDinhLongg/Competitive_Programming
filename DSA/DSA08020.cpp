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
#define pii pair<int, int>

const int mod = 1e9 + 7;
//const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

vector<int> v;
bool nt[10005];

void hehe(){
	for(int i=2; i<=1e2; i++){
		if(!nt[i]){
			for(int j=i*i; j<=1e4; j+=i) nt[j] = 1;
		}
	}
	for(int i=1e3; i<1e4; i++){
		if(!nt[i]) v.pb(i);
	}
}

bool check(int x, int so){
	int cnt = 0;
	while(x > 0 && so > 0){
		if(x % 10 != so % 10) ++cnt;
		if(cnt > 1) return 0;
		x /= 10; so /= 10;
	}return 1;
}

int cal(int s, int t){
	bool mark[10005] = {0};
	queue<pii> q;
	q.push({s, 0});
	mark[s] = 1;
	while(!q.empty()){
		pii x = q.front(); q.pop();
		if(x.fi == t) return x.se;
		for(int &so : v){
			if(!mark[so] && check(x.fi, so)){
				q.push({so, x.se + 1});
				mark[so] = 1;
			}
		}
	}return 0;
}

signed main(){
	LonggVuz();
	
	hehe();
	tc(){
		int s, t; cin >> s >> t;
		cout << cal(s, t) << el;
	}
	
	End();
}