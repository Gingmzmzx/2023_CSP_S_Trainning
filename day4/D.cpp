for (int k = 1; k <= K; k++) {
	
	int t_k;
	
	for (int j = 1; j <= m; j++) {
	
		deque<int> Q;
		
		int g[];
		
		for (int i = 1; i <= n; i++) {
			g[i] = f[k - 1][i][j] + i;
		}
	
		for (int i = n; i; i--) {
			
			while (!Q.empty() && Q.front() > i + t_k) {
				Q.pop_front();
			}
			
			while (!Q.empty() && g[Q.back()] <= g[i]) {
				Q.pop_back();
			}
			
			Q.push_back(i);
			
			f[k][i][j] = g[Q.front()] - i;
				
		}
	
	}
	
}
