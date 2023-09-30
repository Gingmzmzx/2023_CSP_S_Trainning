#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
#include <time.h>

using namespace std;

const int MAXN = 100005;

int n,ans;
int laz[MAXN << 2];
int MIN[MAXN << 2];

void add(int o,int v)
{
	laz[o] += v;
	MIN[o] += v;
}
 
void pushdown(int o)
{
	if (laz[o])
	{
		add(o << 1,laz[o]);
		add(o << 1 | 1,laz[o]);
		laz[o] = 0;
	}
}
 
void modify(int o,int l,int r,int x,int y,int v)
{
	if (l >= x && r <= y)
	{
		add(o,v);
		return;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if (mid >= x)
		modify(o << 1,l,mid,x,y,v);
	if (mid + 1 <= y)
		modify(o << 1 | 1,mid + 1,r,x,y,v);
	MIN[o] = min(MIN[o << 1],MIN[o << 1 | 1]);
}

int main()
{
	freopen("ddl.in","r",stdin);
	freopen("ddl.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		modify(1,1,n,i,n,1);
	for (int k,a,i = 1;i <= n;i++)
	{
		scanf("%d",&k);
		while (k--)
		{
			scanf("%d",&a);
			modify(1,1,n,a,n,-1);
		}
		if (MIN[1] > 0)
			modify(1,1,n,i,n,-1);
		else if (MIN[1] < 0)
		{
			ans -= MIN[1];
			modify(1,1,n,i,n,-MIN[1]);
		}
		modify(1,1,n,i,i,1e9);
	}
	printf("%d\n",ans);
	return 0;
}
