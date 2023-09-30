#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline char gc()
{
	static char buf[524288],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,524288,stdin),p1 == p2) ? EOF : *p1++;
}

void read(int &v)
{
	v = 0;
	char c = gc();
	while (c < '0' || c > '9')
		c = gc();
	while (c >= '0' && c <= '9')
	{
		v = v * 10 + c - '0';
		c = gc();
	}
}

void reads(char *s)
{
	char c = gc();
	while (c != '#' && c != '.')
		c = gc();
	while (c == '#' || c == '.')
	{
		*s = c;
		s++;
		c = gc();
	}
}

const int MAXN = 10000005;
const ll MOD = 998244353;

int n,m,R,C,head,tail;
int dis1[MAXN];
int dis2[MAXN];
int Q[MAXN << 1];
int ed[MAXN][4];
int len[MAXN][4];

char s[MAXN];
char *a[MAXN];

char ans[MAXN];

bool mark[MAXN];

void addE(int u,int v,int w,bool flag)
{
	if (flag)
		swap(u,v);
	for (int i = 0;i < 4;i++)
		if (!ed[u][i])
		{
			ed[u][i] = v;
			len[u][i] = w;
			return;
		}
}

void addEdge(bool flag)
{
	for (int i = 1,e = 1;i <= n;i++)
		for (int j = 1;j <= m;j++,e++)
		{
			if (a[i][j] == '#' && j > 1 && a[i][j - 1] == '#')
				addE(e,e - 1,0,flag);
			if (a[i][j] == '#' && j < m && a[i][j + 1] == '#')
				addE(e,e + 1,0,flag);
			if (a[i][j] == '#' && i > 1)
				addE(e,e - m,0,flag);
			else if (i > 1)
				addE(e,e - m,1,flag);
			if (a[i][j] == '#' && i < n && a[i + 1][j] == '#')
				addE(e,e + m,0,flag);
		}
}

void bfs(int *dis)
{
	while (head <= tail)
	{
		int u = Q[head++];
		if (mark[u])
			continue;
		mark[u] = 1;
		for (int i = 0;i < 4;i++)
		{
			if (!ed[u][i])
				break;
			int to = ed[u][i],l = len[u][i];
			if (dis[to] <= dis[u] + l)
				continue;
			dis[to] = dis[u] + l;
			if (!l)
				Q[--head] = to;
			else
				Q[++tail] = to;
		}
	}
}

int main()
{
	freopen("tetris.in","r",stdin);
	freopen("tetris.out","w",stdout);
	read(n),read(m),read(R),read(C);
	for (int i = 1;i <= n;i++)
	{
		reads(s + (i - 1) * m + 1);
		a[i] = s + (i - 1) * m;
	}
	assert(a[R][C] == '#');
	addEdge(0);
	for (int i = 1;i <= (n - 1) * m;i++)
		dis1[i] = 1e9;
	head = 10000001,tail = 10000000;
	for (int i = (n - 1) * m + 1;i <= n * m;i++)
		Q[++tail] = i;
	bfs(dis1);
	memset(ed,0,sizeof(ed));
	memset(len,0,sizeof(len));
	memset(mark,0,sizeof(mark));
	addEdge(1);
	for (int i = 1;i <= n * m;i++)
		dis2[i] = 1e9;
	dis2[(R - 1) * m + C] = 0;
	head = 10000001,tail = 10000000;
	Q[++tail] = (R - 1) * m + C;
	bfs(dis2);
	ll ANS = 0;
	for (int i = 1,e = 1;i <= n;i++)
		for (int j = 1;j <= m;j++,e++)
			if (a[i][j] == '.')
			{
				int id = 0,od = 0,in[4] = {0},lin[4] = {0},out[4] = {0},lout[4] = {0};
				if (j > 1 && a[i][j - 1] == '#')
				{
					in[id] = e - 1;
					lin[id] = 0;
					id++;
					out[od] = e - 1;
					lout[od] = 0;
					od++;
				}
				if (j < m && a[i][j + 1] == '#')
				{
					in[id] = e + 1;
					lin[id] = 0;
					id++;
					out[od] = e + 1;
					lout[od] = 0;
					od++;
				}
				if (i > 1)
				{
					out[od] = e - m;
					lout[od] = 0;
					od++;
					if (a[i - 1][j] == '#')
					{
						in[id] = e - m;
						lin[id] = 0;
						id++;
					}
				}
				if (i < n && a[i + 1][j] == '#')
				{
					in[id] = e + m;
					lin[id] = 0;
					id++;
					out[od] = e + m;
					lout[od] = 0;
					od++;
				}
				if (i < n && a[i + 1][j] == '.')
				{
					in[id] = e + m;
					lin[id] = 1;
					id++;
				}
				int ans = dis1[(R - 1) * m + C];
				if (i == n)
				{
					for (int k = 0;k < od;k++)
						ans = min(ans,dis2[out[k]] + lout[k]);
				}
				for (int k = 0;k < id;k++)
					for (int l = 0;l < od;l++)
						ans = min(ans,dis1[in[k]] + lin[k] + lout[l] + dis2[out[l]]);
				ANS = (ANS * 2021 + R + ans) % MOD;
			}
	printf("%lld\n",ANS);
	return 0;
}
