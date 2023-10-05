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
	double sum=0,sum2=0;
	for (int i=1;i<=m;i++)
		sum+=a[i],sum2+=1.0*a[i]*a[i];
	double avg=sum/m;
	double ans = sum2 - 2 * sum * avg + m * avg * avg;
	for (int i=m+1;i<=n;i++)
	{
		sum += a[i] - a[i-m];
		sum2 += 1.0*a[i]*a[i] - 1.0*a[i-m]*a[i-m];
		double avg=sum/m;
		ans = min(ans,sum2 - 2 * sum * avg + m * avg * avg);
	}
	printf("%.4lf\n",ans/m);

	return 0;
}
