#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (h[i] > h[j]) {
                swap(h[i], h[j]);
                ans++;
            }
        }
    }

    for (int i = 0; i < n-1; i++) {
        if (h[i] > h[i+1]) {
            int j = i+2;
            while (j < n && h[j] < h[i]) {
                j++;
            }
            if (j == n) {
                j--;
            }
            swap(h[i], h[j]);
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}