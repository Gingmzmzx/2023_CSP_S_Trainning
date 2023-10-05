#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=100010;
const int mo=1000000007;

int n,k,en,q[maxn],size_[maxn],f[maxn],depth[maxn],z[maxn];

int fac[maxn],ifac[maxn];

int ksm(int a,int b)
{
	int ans=1;
	while (b)
	{
		if (b&1) ans=1ll*ans*a%mo;
		a=1ll*a*a%mo;
		b>>=1;
	}
	return ans;
}

struct edge
{
	int e;
	edge *next;
}*v[maxn],ed[maxn<<1];

void add_edge(int s,int e)
{
	en++;
	ed[en].next=v[s];v[s]=ed+en;v[s]->e=e;
}

void bfs(int p)
{
	int front=1,tail=1;
	q[1]=p;
	depth[p]=1;
	f[p]=0;
	while (front<=tail)
	{
		int now=q[front++];
		for (edge *e=v[now];e;e=e->next)
			if (!depth[e->e])
			{
				f[e->e]=now;
				q[++tail]=e->e;
				depth[e->e]=depth[now]+1;
			}
	}
	for (int a=n;a>=1;a--)
	{
		int p=q[a];
		size_[p]++;
		size_[f[p]]+=size_[p];
	}
}

int C(int n,int m)
{
	return 1ll*fac[n]*ifac[m]%mo*ifac[n-m]%mo;
}

int main()
{
	freopen("sell.in","r",stdin);
	freopen("sell.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int a=1;a<n;a++)
	{
		int s,e;
		scanf("%d%d",&s,&e);
		add_edge(s,e);
		add_edge(e,s);
	}
	bfs(1);

	fac[0]=1;
	for (int a=1;a<=n;a++)
		fac[a]=1ll*fac[a-1]*a%mo;
	ifac[n]=ksm(fac[n],mo-2);
	for (int a=n-1;a>=0;a--)
		ifac[a] = 1ll*ifac[a+1]*(a+1)%mo;

	int ans=0;
	for (int a=1;a<=n;a++)
	{
		int cnt=0;
		for (edge *e=v[a];e;e=e->next)
			if (f[e->e]==a) z[++cnt]=size_[e->e];
			else z[++cnt]=n-size_[a];
		sort(z+1,z+cnt+1);
		if (cnt==1)
		{
			ans = (ans + 1ll * fac[n-2] * ifac[n-2-k]) %mo;
		}
		else
		{
			for (int b=1;b<=cnt;b++)
				if (n-1-k <= z[b])
				{
					int num = k-(n-1-z[b]);
					ans = (ans + 1ll * C(z[b]-1,num) * C(k,num) % mo * fac[num] % mo * fac[k-num] % mo)%mo;
				}
		}
	}
	int tot = 1ll*C(n-1,k)*fac[k]%mo;
	printf("%lld\n",1ll*ans*ksm(tot,mo-2)%mo);

	return 0;
}

