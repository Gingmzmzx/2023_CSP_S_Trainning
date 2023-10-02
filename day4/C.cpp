int sum[N][N];

int a[N][N];

int calc(int X1, int Y1, int X2, int Y2) {
	return sum[X2][Y2] - sum[X1 - 1][Y2] - sum[X2][Y1 - 1] + sum[X1 - 1][Y1 - 1];
}

for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= n; j++) {
		sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + a[i][j] - sum[i - 1][j - 1];
	}
}
