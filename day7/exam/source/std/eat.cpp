#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=100010;
const int maxk=5;
const int mo=1000000007;

#define inc(a,b) {a+=b;if (a>=mo) a-=mo;}
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

int n,k,z[maxn],y[maxn],x[maxn];

struct node
{
	int l,r;

	int tag;

	int minv[maxk],cnt[maxk];

	node()
	{
		tag=0;
		memset(minv,0x3f,sizeof(minv));
		memset(cnt,0,sizeof(cnt));
	}
}w[maxn<<2|1];

node operator+(const node &l,const node &r)
{
	node res;
	res.l=l.l;
	res.r=r.r;

	int j=0;
	for (int i=0;i<k;i++)
	{
		x[++j] = l.minv[i];
		x[++j] = r.minv[i];
	}
	sort(x+1,x+j+1);
	j=unique(x+1,x+j+1)-x-1;
	for (int i=j+1;i<=k;i++)
		x[i]=0x3f3f3f3f;
	for (int i=0;i<k;i++)
		res.minv[i] = x[i+1];
	for (int i=0,j=0;i<k;i++)
	{
		while (j+1<k && l.minv[j]<res.minv[i])
			j++;
		if (res.minv[i] == l.minv[j]) inc(res.cnt[i],l.cnt[j]);
	}
	for (int i=0,j=0;i<k;i++)
	{
		while (j+1<k && r.minv[j]<res.minv[i])
			j++;
		if (res.minv[i] == r.minv[j]) inc(res.cnt[i],r.cnt[j]);
	}
	return res;
}

void build(int l,int r,int rt)
{
	if (l==r)
	{
		w[rt].l=w[rt].r=l;
		w[rt].minv[0]=0;
		w[rt].cnt[0]=1;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);

	w[rt]=w[rt<<1]+w[rt<<1|1];
}

void color(int rt,int v)
{
	w[rt].tag += v;
	for (int i=0;i<k;i++)
		w[rt].minv[i] += v;
}

void push_col(int rt)
{
	if (w[rt].tag)
	{
		color(rt<<1,w[rt].tag);
		color(rt<<1|1,w[rt].tag);
		w[rt].tag=0;
	}
}

void modify(int l,int r,int rt,int nowl,int nowr,int v)
{
	if (nowl<=l && r<=nowr)
	{
		color(rt,v);
		return;
	}
	push_col(rt);
	int m=(l+r)>>1;
	if (nowl<=m) modify(lson,nowl,nowr,v);
	if (m<nowr) modify(rson,nowl,nowr,v);
	w[rt]=w[rt<<1]+w[rt<<1|1];
}

node query(int l,int r,int rt,int nowl,int nowr)
{
	if (nowl<=l && r<=nowr) return w[rt];
	int m=(l+r)>>1;
	if (nowl<=m)
	{
		if (m<nowr) return query(lson,nowl,nowr)+query(rson,nowl,nowr);
		else return query(lson,nowl,nowr);
	}
	else return query(rson,nowl,nowr);
}

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
	build(root);

	for (int i=1;i<=n;i++)
	{
		modify(root,1,i,1);
		int p=y[i];
		if (p>1 && z[p-1]<i) modify(root,1,z[p-1],-1);
		if (p<n && z[p+1]<i) modify(root,1,z[p+1],-1);
		node res = query(root,1,i);
		for (int j=0;j<k;j++)
			if (res.minv[j] <= k) inc(ans,res.cnt[j]);
	}

	printf("%d\n",ans);
	fflush(stdout);

	return 0;
}
