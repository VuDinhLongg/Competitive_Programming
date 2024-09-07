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

str f[105][10005];
// f[i][j] : so nho nhat co tong chu so bang i, tong binh phuong chu so bang j

str smin(str a, str b){
	if(a == "") return b;
	if(len(a) == len(b)) return min(a, b);
	if(len(a) < len(b)) return a;
	return b;
}

void hehe(){
	f[0][0] = "0"; 
	f[1][1] = "1";
	for(int i=2; i<=100; i++){
		for(int j=1; j<=8100; j++){
			for(int k=0; k<=9; k++){
				if(i >= k && j >= k * k && f[i - k][j - k * k] != ""){
					str s = f[i - k][j - k * k] + to_string(k);
					f[i][j] = smin(f[i][j], s);
				}
			}sort(all(f[i][j]));
			if(f[i][j][0] == '0') f[i][j].erase(0, 1);
		}
	}
}

signed main(){
	LonggVuz();
	
	hehe();
	tc(){
		int a, b; cin >> a >> b;
		if(f[a][b] != "") cout << f[a][b] << el;
		else cout << "-1\n";
	}
	
	End();
}