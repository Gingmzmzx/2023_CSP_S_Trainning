#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;

namespace gm{
	using namespace std;

	int ad, ax, ay, bx, by;
	int invert(int a, int b){ // 求大整数x模m的逆元y
    	if(b == 0){
	        ad = a;
	        ax = 1;
	        ay = 0;
	    }else{
	        invert(b, a%b);
	    	bx = ax, by = ay;
	        ax = by;
	        ay = bx - by * (a/b);
	    }
		return ax;
	}

	int gcd, x, y, g_bx;
	void gcdext(int a, int b){ // 扩展欧几里得算法
		if (a == 0){
			gcd = b, x = 0, y = 1;
			return;
		}
		gcdext(b%a, a);
		g_bx = x;
		x = y - (b/a) * x;
		y = g_bx;
	}
	
	void reset(){
		gcd = 0, x = 0, y = 0, g_bx = 0, ad = 0, ax = 0, ay = 0, bx = 0, by = 0;
	}
}

int main(){
	freopen("rsa.in", "r", stdin);
	freopen("rsa.out", "w", stdout);
//	freopen("rsa.err", "w", stderr);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin>>q;
	for(int i=0; i<q; i++){
		int n, e1, e2, c1, c2, s1, s2, m;
		cin>>n>>e1>>e2>>c1>>c2;
		gm::gcdext(e1, e2);
		s1 = gm::x;
		s2 = gm::y;
		gm::reset();
		if (s1 < 0){
			s1 = abs(s1);
			c1 = gm::invert(c1, n);
			gm::reset();
		}else if (s2 < 0){
			s2 = abs(s2);
			c2 = gm::invert(c2, n);
			gm::reset();
		}
		long long cs1 = pow(c1, s1), cs2 = pow(c2, s2);
    	m = ( cs1 % n * cs2 % n ) % n;
    	cout<<m<<endl;
	}
	return 0;
}
