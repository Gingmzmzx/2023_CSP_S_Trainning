#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,q,id;
int first[MAXN];
int fa[MAXN];
int ans[MAXN];

bool vis[MAXN];

vector<pair<int,int> > Q[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

void dfs(int u,int f)
{
	vis[u] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != f)
			dfs(edge[i].to,u);
	for (int i = 0;i < Q[u].size();i++)
	{
		int to = Q[u][i].first,ID = Q[u][i].second;
		if (vis[to])
			ans[ID] = getroot(to);
	}
	fa[u] = f;
}

int main()
{
	scanf("%d",&n);
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	for (int i = 1;i <= n;i++)
		fa[i] = i;
	scanf("%d",&q);
	for (int u,v,i = 1;i <= q;i++)
	{
		scanf("%d%d",&u,&v);
		Q[u].push_back(make_pair(v,i));
		Q[v].push_back(make_pair(u,i));
	}
	dfs(1,0);
	for (int i = 1;i <= q;i++)
		printf("%d\n",ans[i]);
	return 0;
}
