// 实现堆排序

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int>& nums, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // 如果左子节点大于根节点
    if (l < n && nums[l] > nums[largest]) {
        largest = l;
    }

    // 如果右子节点大于根节点
    if (r < n && nums[r] > nums[largest]) {
        largest = r;
    }

    // 如果最大值不是根节点
    if (largest != i) {
        swap(nums[i], nums[largest]);
        heapify(nums, n, largest);
    }
}

void heapSort(vector<int>& nums) {
    int n = nums.size();

    // 构建大顶堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(nums, n, i);
    }

    // 一个个交换元素
    for (int i = n - 1; i >= 0; i--) {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}

int main() {
    vector<int> nums = { 1, 3, 2, 6, 5, 7, 4, 9, 8 };
    heapSort(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}