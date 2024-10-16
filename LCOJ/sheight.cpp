// https://luyencode.net/problem/sheight
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
	char c;
	node *l, *r;
	node(char x){
		c = x;
		l = r = NULL;
	}
};

int height(node *x){
	if(x == NULL) return -1;
	return 1 + max(height(x->l), height(x->r));
}

void LonggVuz(){
	string a; cin >> a;
	stack<node*> st;
	for(int i=0; i<len(a); i++){
		if(isalpha(a[i])){
			node *x = new node(a[i]);
			st.push(x);
		}else{
			node *x = st.top(); st.pop();
			node *y = st.top(); st.pop();
			node *z = new node(a[i]);
			z->l = y;
			z->r = x;
			st.push(z);
		}
	}
	node *root = st.top();
	cout << height(root) << el;
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}
