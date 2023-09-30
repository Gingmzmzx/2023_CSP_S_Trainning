#include <stdio.h>
//��Ԫ��gcd(a,b) == ax +by == d;
struct gcdstruct{
    int d;
    int x;
    int y;
};
gcdstruct EXTENDED_EUCLID(int a,int b){
    gcdstruct aa,bb;
    if(b==0){
        aa.d = a;
        aa.x = 1;
        aa.y = 0;
        return aa;
    }else{
        bb = EXTENDED_EUCLID(b,a%b);
        aa.d = bb.d;
        aa.x = bb.y;
        aa.y = bb.x - bb.y * (a/b);
    }
	return aa;
}

//ax == 1 (mod m),��x
long inverse(long a,long m){
	long x;
    gcdstruct aa;
    aa = EXTENDED_EUCLID(a,m);
    return aa.x;
}
int main(){
    int a,m;
    a = 3;
	m = 11;
	printf("a = %d,m = %d,x = %d\n",a,m,inverse(a,m));
	getchar();
    return 0;
}
