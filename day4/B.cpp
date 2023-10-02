int a[N], n, k;

deque<int> Q;

for (int i = 1; i <= n; i++) {
	
	[i - k + 1, i]
	
	while (!Q.empty() && Q.front() <= i - k) {
		Q.pop_front();
	}
	while (!Q.empty() && a[Q.back()] <= a[i]) {
		Q.pop_back();
	}
	Q.push_back(i);
	
	cout << a[Q.front()] << endl;
}
