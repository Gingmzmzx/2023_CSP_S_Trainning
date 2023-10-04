const int maxn=1000010;

int fac[maxn];//fac[i] 代表i!%p
int ifac[maxn];// ifac[i] 代表 1/i! % p

fac[0]=1;
for (int i=1;i<=1000000;i++)
	fac[i] = 1ll * fac[i-1] * i % p;
for (int i=0;i<=1000000;i++)
	ifac[i] = ksm(fac[i],p-2); 

int C(int n,int m)//求C(n,m)% p
//C(n,m) = n! / m! / (n-m)!
{
	return 1ll * fac[n] * ifac[m] % p * ifac[n-m] % p;
}
