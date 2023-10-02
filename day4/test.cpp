#include <iostream>
#include <queue>
using namespace std;
const int N = 1e6 + 10;
int n, k, a[N];
priority_queue<int, vector<int>, greater<int>> q1; // 小根堆
priority_queue<int> q2; // 大根堆

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) {
        if (q2.empty() || a[i] <= q2.top()) q2.push(a[i]);
        else q1.push(a[i]);
        if (q1.size() > q2.size()) {
            q2.push(q1.top());
            q1.pop();
        }
        if (q2.size() > q1.size() + 1) {
            q1.push(q2.top());
            q2.pop();
        }
    }
    cout << (q2.size() > q1.size() ? q2.top() : (q1.top() + q2.top()) / 2) << endl;
    for (int i = k + 1; i <= n; i++) {
        if (a[i - k] <= q2.top()) q2.pop();
        else q1.pop();
        if (q2.empty() || a[i] <= q2.top()) q2.push(a[i]);
        else q1.push(a[i]);
        if (q1.size() > q2.size()) {
            q2.push(q1.top());
            q1.pop();
        }
        if (q2.size() > q1.size() + 1) {
            q1.push(q2.top());
            q2.pop();
        }
        cout << (q2.size() > q1.size() ? q2.top() : (q1.top() + q2.top()) / 2) << endl;
    }
    return 0;
}