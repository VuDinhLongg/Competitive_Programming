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

void make(node *root, int u, int v, char c){
	if(c == 'L') root->l = new node(v);
	else root->r = new node(v);
}

void insert(node *root, int u, int v, char c){
	if(root == NULL) return;
	if(root->val == u){
		make(root, u, v, c);
		return;
	}
	insert(root->l, u, v, c);
	insert(root->r, u, v, c);
}

int level(node *root){
	if(root == NULL) return 0;
	return 1 + max(level(root->l), level(root->r));
}

bool check(node *root, int lev, int h){
	if(root == NULL) return true;
	if(root->l == NULL and root->r == NULL) return lev == h;
	return check(root->l, lev + 1, h) and check(root->r, lev + 1, h);
}

void LonggVuz(){
	int n; cin >> n;
	node *root;
	for(int i=1; i<=n; i++){
		int u, v; char c;
		cin >> u >> v >> c;
		if(i == 1){
			root = new node(u);
			make(root, u, v, c);
		}else insert(root, u, v, c);
	}
	if(check(root, 1, level(root))) cout << "1\n";
	else cout << "0\n";
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}