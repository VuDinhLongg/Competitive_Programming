// https://luyencode.net/problem/thptqh_vp_20_21_3
// LonggVu.
#include<bits/stdc++.h>
using namespace std;
// Noob C++
void End(){
    cerr << "=> Thời gian code chạy: ";
    cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define LonggVu() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
using ll = long long;
using ld = long double;
using str = string;

bool check(int a[], int n){
    for(int i=1; i<=n; i++){
        if(a[i] != i) return 0;
    }return 1;
}

int main(){
    LonggVu();
     use("revnrev")
    int n, k; cin >> n >> k; int a[n+5];
    for(int i=1; i<=n; i++) a[i] = i;
    int u, v, l, r; cin >> u >> v >> l >> r;
	for(int i=1; i<=n; i++){
        reverse(a+u, a+v+1), reverse(a+l, a+r+1);
        if(check(a, n)){
            k %= i; break;
        }
    }
    while(k--){
        reverse(a+u, a+v+1), reverse(a+l, a+r+1);
        // for(int i=1; i<=n; i++) cout << a[i] << ' ';
        // cout << el;
    }for(int i=1; i<=n; i++) cout << a[i] << ' ';
    
    End();
}
