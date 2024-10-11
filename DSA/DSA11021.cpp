// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Legendary Grandmaster
void End(){
    cerr << "=> Smoothly Finished! Time taken: ";
    cerr << (0.001 * clock()) << "s" << string(25, '\t');
}
#define Sonic() cin.tie(NULL) -> sync_with_stdio(false);
#define fix(x) fixed << setprecision(x)
#define all(x) begin(x), end(x)
#define len(x) (int)x.size()
#define gel(x) getline(cin >> ws, x)
#define ms(a, x) memset(a, x, sizeof(a))
#define bit(n, x) (n >> x & 1)
#define pb push_back
#define is insert
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

struct node{
	int val;
	node *l, *r;
	node(int x){
		val = x;
		l = r = NULL;
	}
};

node *build(int a[], int l, int r){
	if(l > r) return NULL;
	if(l == r) return new node(a[l]);
	node *res = new node(a[l]);
	int i = l;
	for(i=l+1; i<=r; i++){
		if(a[i] > a[l]) break;
	}
	res->l = build(a, l + 1, i - 1);
	res->r = build(a, i, r);
	return res;
}

void duyet(node *x){
	if(x == NULL) return;
	if(x->l == NULL and x->r == NULL){
		cout << x->val << ' ';
		return;
	}
	duyet(x->l);
	duyet(x->r);
}

void LonggVuz(){
	int n; cin >> n;
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	node *root = build(a, 0, n - 1);
	duyet(root);
	cout << el;
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}