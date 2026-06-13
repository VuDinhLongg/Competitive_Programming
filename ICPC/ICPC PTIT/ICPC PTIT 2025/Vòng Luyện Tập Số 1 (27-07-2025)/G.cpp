// Author : Nguyễn Bá Hùng - B23DCAT120
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ed "\n"
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define BidenJr 0
int x_4axis[] = {-1, 0, 0, 1};
int y_4axis[] = {0, -1, 1, 0};
int x_8axis[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y_8axis[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int MOD = 1e9 + 7;

int n, m;
int a[300001];

int check(int t){
	int cur = 0;
	for(int i = 0; i < n; i++){
		int tmp = a[i] + t;
		if(tmp < m) {
			if(cur > tmp) return 0;
			cur = max(cur, a[i]);
		} else {
			int b = tmp % m;
			if(cur > b){
				cur = max(cur, a[i]);
			}
		}
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	int l = 0, h = m;
	while(l < h){
		int mid = (l + h) / 2;
		if(check(mid))
			h = mid;
		else
			l = mid + 1;
	}
	cout << l;
	return BidenJr;
}
