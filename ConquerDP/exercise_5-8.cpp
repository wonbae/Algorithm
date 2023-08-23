#include<bits/stdc++.h>
using namespace std;

bool dp[101][10001];
vector<int> elements;

void subsetSum(int n, int sum, const vector<int>& nums) {
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    if (!dp[n][sum]) {
        cout << "false" << endl;
    } else {
        int i = n, j = sum;
        // cout<<"\n\n";

        while (i > 0 && j > 0) {
            // cout<<"("<<i<<","<<j<<")\n";
            // cout<<"dp : "<<dp[i-1][j]<<"\n";
            if (dp[i - 1][j]) {
                i--;
            } else {
                // cout<<"else : "<<nums[i-1]<<"\n";
                elements.push_back(nums[i - 1]);
                j -= nums[i - 1];
                i--;
            }
            // cout<<"\n";
        }
        for (int i = elements.size() - 1; i >= 0; i--) {
            cout << elements[i] << " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    subsetSum(n, x, nums);

    return 0;
}

// 4 6
// 3 2 7 1
