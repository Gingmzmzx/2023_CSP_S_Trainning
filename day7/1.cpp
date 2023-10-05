#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    freopen("buy.in", "r", stdin);
	freopen("buy.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    double ans = 1e18;
    for (int i = 0; i + m - 1 < n; i++) {
        double sum = 0;
        for (int j = i; j < i + m; j++) {
            sum += a[j];
        }
        double mean = sum / m;
        double var = 0;
        for (int j = i; j < i + m; j++) {
            var += (a[j] - mean) * (a[j] - mean);
        }
        ans = min(ans, var / m);
    }

    printf("%.4f", ans);

    return 0;
}