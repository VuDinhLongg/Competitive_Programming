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

bool dau(char c){
	return c == '+' or c == '-' or c == '*' or c == '/';
}

void duyet(node *root){
	if(root == NULL) return;
	duyet(root->l);
	cout << root->c;
	duyet(root->r);
}

void solve(string a){
	stack<node*> st;
	for(int i=0; i<len(a); i++){
		if(!dau(a[i])){
			st.push(new node(a[i]));
		}else{
			node *tmp = new node(a[i]);
			node *phai = st.top(); st.pop();
			node *trai = st.top(); st.pop();
			tmp->l = trai;
			tmp->r = phai;
			st.push(tmp);
		}
	}
	duyet(st.top());
}

void LonggVuz(){
	string a; cin >> a;
	solve(a);
	cout << el;
}

signed main(){
	Sonic();
	
	int TC = 1; cin >> TC;
	while(TC--) LonggVuz();
	
	End();
}