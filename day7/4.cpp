#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

vector<vector<int>> tree;
vector<vector<long long>> dp;
vector<long long> expected_sugar;

void dfs(int u, int parent, int K) {
    dp[u][0] = 1;

    for (int v : tree[u]) {
        if (v == parent) continue;
        dfs(v, u, K);

        // Calculate dp[u][i] using dp[v][j]
        for (int i = 1; i <= K; i++) {
            for (int j = 0; j <= i; j++) {
                dp[u][i] = (dp[u][i] + dp[u][i - j] * dp[v][j]) % MOD;
            }
        }
    }

    // Calculate expected sugar for node u
    expected_sugar[u] = 0;
    for (int i = 0; i <= K; i++) {
        expected_sugar[u] = (expected_sugar[u] + dp[u][i]) % MOD;
    }
}

int main() {
    freopen("sell.in", "r", stdin);
	freopen("sell.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int N, K;
    cin >> N >> K;

    tree.resize(N);
    dp.assign(N, vector<long long>(K + 1, 0));
    expected_sugar.assign(N, 0);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; // Convert to 0-based indexing
        v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(0, -1, K);

    long long total_expected_sugar = 0;
    for (int i = 0; i < N; i++) {
        total_expected_sugar = (total_expected_sugar + expected_sugar[i]) % MOD;
    }

    cout << total_expected_sugar << endl;

    return 0;
}
