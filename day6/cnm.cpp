int C[maxn][maxn];

for (int i=0;i<=n;i++)
{
	C[i][0] = 1;
	for (int j=1;j<=i;j++)
		C[i][j] = (C[i-1][j-1] + C[i-1][j]) % p; 
}
