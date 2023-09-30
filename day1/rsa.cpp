#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

int q;

ll N,c1,c2,e1,e2;

ll mul(ll a,ll b,ll p)
{
	ll res = 0;
	while (b)
	{
		if (b & 1)
			res = (res + a) % p;
		a = (a + a) % p;
		b >>= 1;
	}
	return res;
}

ll power(ll a,ll b,ll p)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = mul(res,a,p);
		a = mul(a,a,p);
		b >>= 1;
	}
	return res;
}

void exgcd(ll a,ll b,ll &x,ll &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return;
	}
	exgcd(b,a % b,y,x);
	y -= a / b * x;
}

ll inv(ll a,ll p)
{
	ll x,y;
	exgcd(a,p,x,y);
	return (x % p + p) % p;
}

int main()
{
	freopen("rsa.in","r",stdin);
	freopen("rsa.out","w",stdout);
	scanf("%d",&q);
	while (q--)
	{
		scanf("%lld%lld%lld%lld%lld",&N,&e1,&e2,&c1,&c2);
		while (1)
		{
			if (e1 < e2)
			{
				swap(e1,e2);
				swap(c1,c2);
			}
			if (!e2)
				break;
			ll k = e1 / e2;
			c1 = mul(c1,inv(power(c2,k,N),N),N);
			e1 %= e2;
		}
		printf("%lld\n",c1);
	}
	return 0;
}
