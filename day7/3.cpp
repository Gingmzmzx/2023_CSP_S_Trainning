#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("eat.in", "r", stdin);
	freopen("eat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int N, K;
    cin >> N >> K;

    vector<int> a(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int S = 0; S < (1 << N); S++) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (S & (1 << i)) {
                cnt++;
            }
        }
        if (cnt <= K) {
            bool ok = true;
            for (int i = 1; i <= N; i++) {
                if (!(S & (1 << (i-1)))) {
                    int max_val = -1, min_val = 1e9;
                    for (int j = i-K; j <= i+K; j++) {
                        if (j >= 1 && j <= N && (S & (1 << (j-1)))) {
                            max_val = max(max_val, a[j]);
                            min_val = min(min_val, a[j]);
                        }
                    }
                    if (max_val >= a[i] || min_val <= a[i]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}