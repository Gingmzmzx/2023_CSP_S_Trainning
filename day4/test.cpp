#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 998244353;

// 求阶乘
int factorial(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res = (long long)res * i % mod;
    }
    return res;
}

// 求组合数
int C(int n, int m) {
    if (m > n) {
        return 0;
    }
    int res = 1;
    for (int i = 1; i <= m; i++) {
        res = (long long)res * (n - i + 1) % mod;
        res = (long long)res * (long long)i % mod;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    // I
    cout << C(m, n) << endl;

    // II
    cout << C(m, n) * factorial(n) % mod << endl;

    // III
    cout << C(m - 1, n - 1) << endl;

    // IV
    cout << C(n + m - 1, n - 1) << endl;

    // V
    cout << C(n, m) << endl;

    // VI
    cout << C(n - 1, m - 1) << endl;

    // VII
    cout << C(n + m - 1, n - 1) << endl;

    // VIII
    cout << C(n, m) << endl;

    // IX
    cout << 1 << endl;

    // X
    cout << C(n + m - 1, n - 1) << endl;

    // XI
    cout << (m >= n ? 1 : 0) << endl;

    // XII
    cout << 1 << endl;

    return 0;
}