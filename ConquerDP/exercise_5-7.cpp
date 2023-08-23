// DP로 시간 복잡도 O(nlogn), 추가 메모리 크기 O(1)에 구현하는건 불가능
// Two Pointer 방식으로 구현

#include <bits/stdc++.h>
using namespace std;

void findPairsWithSumX(const vector<int>& nums, int targetSum) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == targetSum) {
            cout << nums[left] << " " << nums[right] << "\n";
            left++;
            right--;
        } else if (sum < targetSum) {
            left++;
        } else {
            right--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    findPairsWithSumX(nums, x);

    return 0;
}
