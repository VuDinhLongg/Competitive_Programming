/*======================
   Author : @LonggVuz
======================*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define dbg(...) 1608
#define orz(...) 2005
#endif

#define el cout << '\n'
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define out(x) return void(cout << (x) << '\n')
#define rep(i, n) for(int32_t i=0; i<n; ++i)
#define fo(i, a, b) for(int32_t i=a; i<=b; ++i)
#define fd(i, a, b) for(int32_t i=a; i>=b; --i)
#define maxi(a, b) ((a) < (b) ? (a = b, 1) : 0)
#define mini(a, b) ((a) > (b) ? (a = b, 1) : 0)
#define int long long
#define mxn 1'000'007



inline void LonggVuz(){
	int d; string m;
	cin >> d >> m;
	if(m == "Jan"){
		cout << (d <= 20 ? "Capricorn" : "Aquarius");
	}else if(m == "Feb"){
		cout << (d <= 19 ? "Aquarius" : "Pisces");
	}else if(m == "Mar"){
		cout << (d <= 20 ? "Pisces" : "Aries");
	}else if(m == "Apr"){
		cout << (d <= 20 ? "Aries" : "Taurus");
	}else if(m == "May"){
		cout << (d <= 20 ? "Taurus" : "Gemini");
	}else if(m == "Jun"){
		cout << (d <= 21 ? "Gemini" : "Cancer");
	}else if(m == "Jul"){
		cout << (d <= 22 ? "Cancer" : "Leo");
	}else if(m == "Aug"){
		cout << (d <= 22 ? "Leo" : "Virgo");
	}else if(m == "Sep"){
		cout << (d <= 21 ? "Virgo" : "Libra");
	}else if(m == "Oct"){
		cout << (d <= 22 ? "Libra" : "Scorpio");
	}else if(m == "Nov"){
		cout << (d <= 22 ? "Scorpio" : "Sagittarius");
	}else{
		cout << (d <= 21 ? "Sagittarius" : "Capricorn");
	}
	el;
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	signed o = 1; if(1) cin >> o;
	rep(x, o) orz(x), LonggVuz();
	
	cerr << "[exec time = `" << clock() << "ms`]";
}
