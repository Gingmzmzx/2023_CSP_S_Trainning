
int ctz[1 << N];
long long f[1 << N], g[1 << N];
long long c[N];
const long long p = 998244353;

cin >> n >> m;

for (int i = 0; i < m; i++) {
	cin >> x >> y;
	c[x] |= 1 << y;
	c[y] |= 1 << x;
}

for (int i = 0; i < n; i++) {
	ctz[1 << i] = i;
}

for (int S = 1; S < 1 << n; S++) {
	int x = ctz[S & -S];
	g[S] = max(g[S - (1 << x)], g[S - (1 << x) - (c[x] & S)] + 1);
}

f[0] = 1;
for (int S = 1; S < 1 << n; S++) {
	for (int x = 0; x < n; x++) {
		if (~S >> x & 1) <=> if (!(S >> x & 1))
			continue;
		if (g[S - (1 << x) - (c[x] & S)] + 1 < g[S])
			continue;
		f[S] = (f[S] + f[S - (1 << x) - (c[x] & S)]) % p;
	}
}

cout << f[(1 << n) - 1] /n! << endl; 






/* topo count */
	
long long f[1 << N];

bool valid(int x, int S) {
	return S 没有连向 x 的边; 
}

for (int S = 1; S < 1 << n; S++) {
	for (int x = 0; x < n; x++) {
		if (~S >> x & 1)
			continue;
		if (valid(x, S))
			f[S] += f[S - (1 << x)];
	}
}

/* topo count with edge subset */

long long count[N][1 << N];

cin >> n >> m;

for (int i = 0; i < m; i++) {
	cin >> x >> y;
	for (int S = 1; S < 1 << n; S++) {
		if (S >> y & 1)
			count[x][S]++;
	}
}

for (int S = 1; S < 1 << n; S++) {
	for (int x = 0; x < n; x++) {
		if (~S >> x & 1)
			continue;
		f[S] += f[S - (1 << x)] << count[x][S - (1 << x)];
	}
}


/* subset */

fixed S
for (int T = S; T >= 0; T = (T - 1) & S) {
	
	/**/
	
	if (T == 0)
		break;
}	
