#include<bits/stdc++.h>
using namespace std;
int n, x;
long long sum;
priority_queue<int, vector<int>, less<int> > a;
int main(){
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	n = 2 * n + 1;
	for(int i=1; i<=n; i++){
		cin>>x;
		a.push(x);
	}
	x = n / 2 + 1;
	for(int i=1; i<=x; i++){
		int ttop = a.top();
		a.pop();
		sum += ttop;
	}
	cout<<sum<<endl;
	return 0;
}

