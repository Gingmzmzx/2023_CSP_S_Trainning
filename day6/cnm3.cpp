int C(int n,int m)
{
	for (int i=1;i<=m;i++)
	{
		fenzi[i] = n-i+1;
		fenmu[i] = i;
	}
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++)
		{
			int g=gcd(fenzi[i],fenmu[j]);
			fenzi[i] /= g;
			fenmu[j] /= g;
		}
	int ans=1;
	for (int i=1;i<=m;i++)
		ans = 1ll*ans*fenzi[i]%p;
	return ans;
}
