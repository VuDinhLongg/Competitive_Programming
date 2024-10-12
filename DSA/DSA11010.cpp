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

void make(node *root, int val, char c){
	if(c == 'L') root->l = new node(val);
	else root->r = new node(val);
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

int h;
int height(node *root){
	if(root == NULL) return 0;
	return 1 + max(height(root->l), height(root->r));
}

bool check1(node *root, int level){
	if(root == NULL) 
		return level == h;
	return check1(root->l, level + 1) and check1(root->r, level + 1);
}

bool check2(node *root){
	if(root == NULL) 
		return 1;
	if((root->l and root->r) or (!root->l and !root->r)) 
		return check2(root->l) and check2(root->r);
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
	h = height(root);
	if(check1(root, 0) and check2(root)) cout << "Yes\n";
	else cout << "No\n";
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}