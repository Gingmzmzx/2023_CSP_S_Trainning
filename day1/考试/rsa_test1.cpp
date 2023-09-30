#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;

namespace gm{
	using namespace std;
	
	int ad, ax, ay, bx, by;
	int invert(int a, int b){
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
	void gcdext(int a, int b){
		if (a == 0){
			gcd = b, x = 0, y = 1;
			return;
		}
		gcdext(b%a, a);
		g_bx = x;
		x = y - (b/a) * x;
		y = g_bx;
	}
}

int main(){
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
//	freopen(".err", "w", stderr);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<gm::invert(3, 11)<<" "<<gm::invert(5, 7)<<endl;
	gm::gcdext(5, 7);
	cout<<gm::gcd<<" "<<gm::x<<" "<<gm::y<<endl;
	gm::gcdext(3, 5);
	cout<<gm::gcd<<" "<<gm::x<<" "<<gm::y<<endl;
	return 0;
}

