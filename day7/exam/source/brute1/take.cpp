#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int maxn=1010;

int n,m,en,ans[maxn][maxn],a[maxn];

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

int dfs(int root,int now,int fa,int nowv)
{
	for (edge *e=v[now];e;e=e->next)
		if (e->e!=fa)
			ans[root][now]=max(ans[root][now],dfs(root,e->e,now,nowv+a[now]));
	ans[root][now] += nowv+a[now];
	return ans[root][now] - nowv; 
}

int main()
{
	freopen("take.in","r",stdin);
	freopen("take.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
	{
		int s,e;
		scanf("%d%d",&s,&e);
		add_edge(s,e);
		add_edge(e,s);
	}
	for (int i=1;i<=n;i++)
		dfs(i,i,0,0);

	for (int i=1;i<=m;i++)
	{
		int p1,p2;
		scanf("%d%d",&p1,&p2);
		printf("%d\n",ans[p1][p2]);
	}

	return 0;
}
