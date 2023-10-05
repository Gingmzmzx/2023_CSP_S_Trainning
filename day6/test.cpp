#include <bits/stdc++.h>

using namespace std;

int n,A[5140],dp[5140];

int maxn=-1e9;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>A[i];
	}
	for (int i=1;i<=n;i++){
		dp[i]=1;
		for (int j=1;j<=i;j++){
			if(A[j]<A[i]&&dp[i]<dp[j]+1)dp[i]=dp[j]+1;
		}
		if(dp[i]>maxn)maxn=dp[i];
	}
	cout<<maxn;
	return 0;
}