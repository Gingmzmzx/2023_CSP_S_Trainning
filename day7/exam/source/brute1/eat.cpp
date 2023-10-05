#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=100010;

int n,k,z[maxn],y[maxn];

bool cmp(int a,int b)
{
	return z[a]<z[b];
}

int main()
{
	freopen("eat.in","r",stdin);
	freopen("eat.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&z[i]);
		y[i]=i;
	}
	sort(y+1,y+n+1,cmp);
	for (int i=1;i<=n;i++)
		z[y[i]]=i;

	int ans=0;
	for (int l=1;l<=n;l++)
		for (int r=l;r<=n;r++)
		{
			bool vis=false;
			int cnt=0;
			for (int i=1;i<=n;i++)
				if (l<=z[i] && z[i]<=r)
				{
					if (!vis) cnt++;
					vis=true;
				}
				else vis=false;
			if (cnt<=k) ans++;
		}
	printf("%d\n",ans);

	return 0;
}
