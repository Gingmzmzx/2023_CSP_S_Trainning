for (int i = 0; i < n; i++) {
	for (int s = 0; s < 1 << n; s++) {
		if (s >> i & 1)
			f[s] += f[s - (1 << i)];
	}
} 

int a[N][N][N][N];

for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			for (int l = 0; l < n; l++) {
				if (i > 0)
					a[i][j][k][l] += a[i - 1][j][k][l];			
			}
		}
	}
}


for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			for (int l = 0; l < n; l++) {
				if (j > 0)
					a[i][j][k][l] += a[i][j - 1][k][l];			
			}
		}
	}
}


for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			for (int l = 0; l < n; l++) {
				if (k > 0)
					a[i][j][k][l] += a[i][j][k - 1][l];			
			}
		}
	}
}



for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			for (int l = 0; l < n; l++) {
				if (l > 0)
					a[i][j][k][l] += a[i][j][k][l - 1];			
			}
		}
	}
}
