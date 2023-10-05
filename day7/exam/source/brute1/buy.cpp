#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=100010;

int n,m,a[maxn];

int main()
{
	freopen("buy.in","r",stdin);
	freopen("buy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	double ans = 1e20;
	for (int i=1;i<=n-m+1;i++)
	{
		double sum=0,sum2=0;
		for (int j=i;j<=i+m-1;j++)
			sum+=a[j],sum2+=1.0*a[j]*a[j];
		double avg=sum/m;
		ans = min(ans,sum2 - 2 * sum * avg + m * avg * avg);
	}
	printf("%.4lf\n",ans/m);

	return 0;
}
