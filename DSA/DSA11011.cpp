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

void make(node *root, int x, char c){
	if(c == 'L') root->l = new node(x);
	else root->r = new node(x);
}

void insert(node *root, int x, int y, char c){
	if(root == NULL) return;
	if(root->val == x){
		make(root, y, c);
		return;
	}
	insert(root->l, x, y, c);
	insert(root->r, x, y, c);
}

bool check(node *root){
	if(root->l == NULL and root->r == NULL) 
		return 1;
	if(root->l != NULL and root->r != NULL)
		return check(root->l) and check(root->r);
	return 0;
}

void LonggVuz(){
	int n; cin >> n;
	node *root;
	for(int i=0; i<n; i++){
		int x, y; char c;
		cin >> x >> y >> c;
		if(!i){
			root = new node(x);
			make(root, y, c);
		}else insert(root, x, y, c);
	}
	cout << check(root) << el;
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}