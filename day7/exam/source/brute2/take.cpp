#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int maxn=100010;

int n,m,en,f[maxn][20],depth[maxn],dp[maxn],a[maxn],sum[maxn];

priority_queue<pair<int,int> > heap[maxn];

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

void dfs(int now,int fa)
{
	depth[now] = depth[fa] + 1;
	sum[now] = sum[fa] + a[now];
	f[now][0] = fa;
	for (int i=1;i<=18;i++)
		f[now][i] = f[f[now][i-1]][i-1];

	for (edge *e=v[now];e;e=e->next)
		if (e->e!=fa)
		{
			dfs(e->e,now);
			dp[now] = max(dp[now],dp[e->e]);
			heap[now].push(make_pair(dp[e->e],e->e));
		}
	dp[now] += a[now];
}

void dfs(int now,int fa,int nowv)
{
	for (edge *e=v[now];e;e=e->next)
		if (e->e!=fa) 
		{
			if (e->e != heap[now].top().second) dfs(e->e,now,a[now]+max(heap[now].top().first,nowv));
			else
			{
				pair<int,int> tmp=heap[now].top();
				heap[now].pop();
				int v=0;
				if (heap[now].size()>0) v=heap[now].top().first;
				dfs(e->e,now,a[now]+max(nowv,v));
				heap[now].push(tmp);
			}
		}
	
	if (now!=1) heap[now].push(make_pair(nowv,fa));
}

int get_lca(int p1,int p2)
{
	if (depth[p1]<depth[p2]) swap(p1,p2);
	for (int i=18;i>=0;i--)
		if (depth[f[p1][i]] >= depth[p2]) p1=f[p1][i];
	if (p1==p2) return p1;
	for (int i=18;i>=0;i--)
		if (f[p1][i]!=f[p2][i]) p1=f[p1][i],p2=f[p2][i];
	return f[p1][0];
}

int jump(int p,int x)
{
	for (;x--;)
		p=f[p][0];
	return p;
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
	dfs(1,0);
	dfs(1,0,0);

	for (int i=1;i<=m;i++)
	{
		int p1,p2;
		scanf("%d%d",&p1,&p2);

		int ans;
		if (p1==p2) ans=heap[p1].top().first+a[p1];
		else
		{
			int lca = get_lca(p1,p2);
			ans = sum[p1]+sum[p2]-sum[lca]-sum[lca]+a[lca];
			int p3;
			if (lca == p2) p3 = jump(p1,depth[p1]-depth[p2]-1);	
			else p3 = f[p2][0];
			if (heap[p2].top().second != p3) ans+=heap[p2].top().first;
			else if (heap[p2].size()>1)
			{
				pair<int,int> tmp=heap[p2].top();
				heap[p2].pop();
				ans += heap[p2].top().first;
				heap[p2].push(tmp);
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}

