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
#define int intmax_t
#define ld long double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

vector<int> aim;
map<vector<int>, int> dem;

void hehe(){
	aim.resize(11);
	aim[1] = 1; aim[2] = 2; aim[3] = 3;
	aim[4] = 8; aim[5] = aim[6] = 0; aim[7] = 4;
	aim[8] = 7; aim[9] = 6; aim[10] = 5;
}

bool check(vector<int> a){
	for(int i=1; i<=10; i++){
		if(a[i] != aim[i]) return 0;
	}return 1;
}

void edit1(vector<int> &a){
	int tmp = a[1];
	swap(a[2], tmp);
	swap(a[6], tmp);
	swap(a[9], tmp);
	swap(a[8], tmp);
	swap(a[4], tmp);
	swap(a[1], tmp);
}

void edit2(vector<int> &a){
	int tmp = a[2];
	swap(a[3], tmp);
	swap(a[7], tmp);
	swap(a[10], tmp);
	swap(a[9], tmp);
	swap(a[5], tmp);
	swap(a[2], tmp);
}

void edit3(vector<int> &a){
	int tmp = a[1];
	swap(a[4], tmp);
	swap(a[8], tmp);
	swap(a[9], tmp);
	swap(a[6], tmp);
	swap(a[2], tmp);
	swap(a[1], tmp);
}

void edit4(vector<int> &a){
	int tmp = a[2];
	swap(a[5], tmp);
	swap(a[9], tmp);
	swap(a[10], tmp);
	swap(a[7], tmp);
	swap(a[3], tmp);
	swap(a[2], tmp);
}

int cal(vector<int> a){
	if(check(a)) return 6;
	queue<vector<int>> q;
	q.push(a);
	while(!q.empty()){
		vector<int> x = q.front(); q.pop();
		if(check(x)) break;
		vector<int> y = x, z = x;
		edit1(y); edit2(z);
		if(!dem[y]){
			q.push(y);
			dem[y] = dem[x] + 1;
		}
		if(!dem[z]){
			q.push(z);
			dem[z] = dem[x] + 1;
		}
		if(dem[z] == 14) break;
	}int res = oo;
	queue<pair<vector<int>, int>> q2;
	q2.push({aim, 0});
	while(!q2.empty()){
		pair<vector<int>, int> x = q2.front(); q2.pop();
		if(dem[x.fi]){
			res = min(res, dem[x.fi] + x.se);
		}
		if(x.se == 14) break;
		vector<int> y = x.fi, z = x.fi;
		edit3(y); edit4(z);
		q2.push({y, x.se + 1});
		q2.push({z, x.se + 1});
	}return res;
}

signed main(){
	LonggVuz();
	
	hehe();
	tc(){
		dem.clear();
		vector<int> a(11, 0);
		for(int i=1; i<=10; i++){
			cin >> a[i];
		}cout << cal(a) << el;
	}
	
	End();
}