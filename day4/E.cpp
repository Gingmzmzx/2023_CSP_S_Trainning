int a[N], pos[N];

cin >> n;
for (int i = 1; i <= n; i++) {
	cin >> a[i];
	pos[a[i]] = i;
}

for (int S = VALUE_MAX; S > 0; S--) {
	f[S] += 1;
	for (int T = (S - 1) & S; T > 0; T = (T - 1) & S) {
		if (pos[S] < pos[T])
			f[T] += f[S];
	}
	ans += f[S] - 1;
}
