#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> shoes(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> shoes[i];
    }

    // 统计左脚鞋和右脚鞋的数量
    int left_count = 0, right_count = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (shoes[i] < 0) {
            left_count++;
        } else {
            right_count++;
        }
    }

    // 如果左右脚鞋的数量不相等，则无法构成合法排列
    if (left_count != right_count) {
        cout << -1 << endl;
    } else {
        // 统计需要对调的次数
        int count = 0;
        for (int i = 0; i < n; i++) {
            int left_shoe = find(shoes.begin(), shoes.end(), -(i+1)) - shoes.begin();
            int right_shoe = find(shoes.begin(), shoes.end(), i+1) - shoes.begin();
            // 如果左右脚鞋的位置编号差为奇数，则无法构成合法排列
            if (abs(left_shoe - right_shoe) % 2 == 1) {
                cout << -1 << endl;
                break;
            }
            count += abs(left_shoe - right_shoe) / 2;
        }
        if (count == n) {
            cout << count << endl;
        }
    }

    return 0;
}