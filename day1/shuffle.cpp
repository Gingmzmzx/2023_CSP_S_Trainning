#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
int n;
int a[MAXN];

int main()
{
	freopen("shuffle.in","r",stdin);
	freopen("shuffle.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= 2 * n + 1;i++)
		cin >> a[i];
	sort(a + 1,a + n * 2 + 2);
	long long sum = 0;
	for(int i = n + 1;i <= 2 * n + 1;++i)
		sum += a[i];
	cout << sum << endl;
	return 0;
}
